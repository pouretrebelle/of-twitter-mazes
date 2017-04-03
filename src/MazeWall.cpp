#include "MazeWall.h"

MazeWall::MazeWall(int _x, int _y, bool _horizontal, bool _disabled) {
  x = _x;
  y = _y;
  horizontal = _horizontal;
  disabled = _disabled;
  active = true;
}

void MazeWall::draw(float unitSize) {
  // don't draw inactive walls
  if (!active) return;

  ofPushMatrix();
  ofTranslate(x*unitSize, y*unitSize);
  if (horizontal) {
    ofDrawLine(0, 0, unitSize, 0);
  }
  else {
    ofDrawLine(0, 0, 0, unitSize);
  }
  ofPopMatrix();
}

void MazeWall::activate() {
  if (!disabled) active = true;
}

void MazeWall::deactivate() {
  if (!disabled) active = false;
}
