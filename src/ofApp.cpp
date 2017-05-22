#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  maze.setup(930, 20, 9, 46, 6, 8, ofColor::black, ofColor::white);
  twitter.setup(&maze);
  color = ofColor::crimson;
}

//--------------------------------------------------------------
void ofApp::update() {
  twitter.update();
  if (maze.mazePath.complete) {
    // maze.regenerate();
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofBackground(255);
  maze.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  switch (key) {
    case 356:
      maze.go("left", color);
      break;
    case 357:
      maze.go("up", color);
      break;
    case 358:
      maze.go("right", color);
      break;
    case 359:
      maze.go("down", color);
      break;
    case 32:
      // spacebar
      maze.regenerate();
      break;
  }


  if (key > 96 && key < 122) {
    if (key - 97 < colors.size()) {
      color = colors[key - 97];
    }
    else {
      color = colors[ofRandom(colors.size())];
    }
  }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
  twitter.saveImage("current");
}
