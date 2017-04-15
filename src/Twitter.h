#pragma once
#include "ofMain.h"
#include "Maze.h"
#include "ofxOsc.h"

#define PORT_IN 6001
#define PORT_OUT 6002

class Twitter {

public:

  Twitter();

  void setup(Maze * _maze);
  void update();
  void saveImage(string name);
  void processTweet(string text, string color);
  void mazeCompleted();

  ofxOscReceiver receiver;
  ofxOscSender sender;

  ofImage image;
  Maze * maze;

private:

};
