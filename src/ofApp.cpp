#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  maze.setup(824, 20, 12, 4, 6, ofColor::black, ofColor::white);
}

//--------------------------------------------------------------
void ofApp::update(){
  if (maze.mazePath.complete) {
    maze.regenerate();
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(255);
  ofTranslate(100, 100);
  maze.drawWalls();
  maze.drawUnits();
  maze.drawPath();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  switch (key) {
    case 356:
      maze.go("left");
      break;
    case 357:
      maze.go("up");
      break;
    case 358:
      maze.go("right");
      break;
    case 359:
      maze.go("down");
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
