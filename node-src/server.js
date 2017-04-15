'use strict';

var Twitter = require('twitter');
var express = require('express');
var deasync = require('deasync');
var env = require('dotenv').config();
var fs = require('fs');
var osc = require('node-osc');

let trackingId = '';

// setup server
var app = express();

// health check
var healthcheck = {
  version: require('./package').version,
  http: 'okay'
};
// healthcheck info public
app.get(['/healthcheck'], function(req, res) {
  res.jsonp(healthcheck);
});

// setup twitter client
var client = new Twitter({
  consumer_key: process.env.CONSUMER_KEY,
  consumer_secret: process.env.CONSUMER_SECRET,
  access_token_key: process.env.ACCESS_TOKEN_KEY,
  access_token_secret: process.env.ACCESS_TOKEN_SECRET
});


// Setup OSC sender and receiver
//=====================================

var oscClient = new osc.Client('127.0.0.1', 6001);
var oscServer = new osc.Server(6002, '127.0.0.1');


// Stream tweets mentioning mazingbot
//=====================================

client.stream('statuses/filter', {track: '@mazingbot'}, function(stream) {
  stream.on('data', function(event) {
    // if the streamed tweet is a reply to the tracked one then respond to it
    if (event.in_reply_to_status_id_str == trackingId) {
      respondToTweet(event);
    }
  });
  stream.on('error', function(error) {
    throw error;
  });
});


// Send initial maze
//=====================================

function newMaze() {
  var image = fs.readFileSync('../bin/data/new.jpg');
  var imageId = uploadMedia(image);
  if (imageId) {
    var tweetId = postTweet({
      status: 'Tweet me directions',
      mediaId: imageId
    }).id_str;
    trackingId = tweetId;
  }
}


// Respond to maze completion message
//=====================================

oscServer.on('message', function (msg, rinfo) {
  if (msg[2][0] == '/complete') {
    // var image = fs.readFileSync('../bin/data/complete.jpg');
    // var imageId = uploadMedia(image);
    // var tweetData = postTweet({
    //   status: 'yay we completed the maze!',
    //   mediaId: imageId,
    // });
    newMaze();
  }
});


// Respond to a tweet
//=====================================

function respondToTweet(event) {
  oscClient.send('/update', event.text, event.user.profile_link_color, function (err) {
    if (err) {
      console.error(new Error(err));
    }
    else {
      // leave a second so oF has time to do its thang
      setTimeout(function() {sendReply(event)}, 1000);
    }
  });
}

function sendReply(event) {
  var image = fs.readFileSync('../bin/data/current.jpg');
  var imageId = uploadMedia(image);
  var tweetData = postTweet({
    status: '@'+event.user.screen_name,
    mediaId: imageId,
    replyId: event.id_str,
  });

  if (tweetData) {
    trackingId = tweetData.id_str;
  }
}


// Post a tweet
//=====================================

function postTweet(data) {
  var ret;
  var tweetData = {
    status: data.status,
    media_ids: data.mediaId // Pass the media id string
  }

  // if it's in reponse to an id
  if (data.replyId) tweetData.in_reply_to_status_id = data.replyId;

  client.post('statuses/update', tweetData, function(error, data, response) {
    if (!error) {
      // return the data of successful tweet;
      ret = data;
    }
    else {
      ret = false;
    }
  });
  deasync.loopWhile(function(){ return ret === undefined });
  return ret;
}


// Upload an image
//=====================================

function uploadMedia(image) {
  var ret;
  client.post('media/upload', {media: image}, function(error, data, response) {
    if (!error) {
      ret = data.media_id_string;
    }
    else {
      ret = false;
    }
  });
  deasync.loopWhile(function(){ return ret === undefined });
  return ret;
}


// start the server
var server = app.listen(process.env.PORT || 2000, function () {
  var host = server.address().address;
  var port = server.address().port;
  console.log('Example app listening at http://%s:%s', host, port);
});
server.timeout = 0;

// Post new maze on server start
oscClient.send('/initialise', function (err) {
  if (!err) {
    setTimeout(newMaze, 1000);
  }
});
