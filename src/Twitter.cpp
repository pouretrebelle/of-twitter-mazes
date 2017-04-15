#include "Twitter.h"

Twitter::Twitter() {
}

void Twitter::setup(Maze * _maze) {
  maze = _maze;
  receiver.setup(PORT_IN);
  sender.setup("127.0.0.1", PORT_OUT);
}

void Twitter::update() {
  while (receiver.hasWaitingMessages()) {

    // get the next message
    ofxOscMessage m;
    receiver.getNextMessage(m);

    if (m.getAddress() == "/update") {
      string text = m.getArgAsString(0);
      string color = m.getArgAsString(1);
      processTweet(text, color);
    }

    // means that node app has started
    if (m.getAddress() == "/initialise") {
      // save initial image
      maze->regenerate();
      saveImage("new");
    }
  }
}

void Twitter::saveImage(string name) {
  maze->draw();
  image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
  image.save(name+".jpg", OF_IMAGE_QUALITY_BEST);
}

void Twitter::processTweet(string text, string color) {
  // covert string to hexadecimal and make an ofColor with it
  ofColor c = ofColor::fromHex(std::stoi(color, 0, 16));

  // convert the tweet to lowercase
  transform(text.begin(), text.end(), text.begin(), ::tolower);

  // loop through text to create vector of words
  vector<string> words;
  istringstream iss(text);
  while (iss) {
    string word;
    iss >> word;
    words.push_back(word);
  }

  // loop through vector and send instruction
  for (int i = 0; i < words.size(); i++) {
    // do the things
    maze->go(words[i], c);
  }

  // save the new image
  saveImage("current");

  if (maze->mazePath.complete == true) {
    mazeCompleted();
  }
}

void Twitter::mazeCompleted() {
  // save the complete maze
  saveImage("complete");

  // regenerate and save
  maze->regenerate();
  saveImage("new");

  // send word to node to tweet new maze
  ofxOscMessage m;
  m.setAddress("/complete");
  sender.sendMessage(m);
}
