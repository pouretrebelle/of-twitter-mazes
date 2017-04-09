#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  maze.setup(930, 20, 9, 6, 8, ofColor::black, ofColor::white);
  twitter.setup(&maze);
}

//--------------------------------------------------------------
void ofApp::update(){
  if (maze.mazePath.complete) {
    // maze.regenerate();
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(255);
  ofTranslate(46, 46);
  maze.drawWalls();
  maze.drawUnits();
  maze.drawPath();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
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
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  maze.regenerate();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
