#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  maze.setup(930, 20, 9, 6, 8, ofColor::black, ofColor::white);
  twitter.setup(&maze);
}

//--------------------------------------------------------------
void ofApp::update() {
  if (maze.mazePath.complete) {
    // maze.regenerate();
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofBackground(255);
  ofTranslate(46, 46);
  maze.drawWalls();
  maze.drawUnits();
  maze.drawPath();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  switch (key) {
    case 356:
      maze.go("left", ofColor::orchid);
      break;
    case 357:
      maze.go("up", ofColor::hotPink);
      break;
    case 358:
      maze.go("right", ofColor::lightCoral);
      break;
    case 359:
      maze.go("down", ofColor::lightSalmon);
      break;
    case 32:
      // spacebar
      maze.regenerate();
      break;
  }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
  maze.regenerate();
}
