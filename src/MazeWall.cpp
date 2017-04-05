#include "MazeWall.h"

MazeWall::MazeWall(int _x, int _y, bool _horizontal, bool _disabled) {
  x = _x;
  y = _y;
  horizontal = _horizontal;
  disabled = _disabled;
  active = true;
}

void MazeWall::draw(float unitSize, int wallWidth) {
  // don't draw inactive walls
  if (!active) return;

  ofPushMatrix();
  ofTranslate(x*unitSize - wallWidth/2, y*unitSize - wallWidth / 2);
  if (horizontal) {
    ofDrawRectangle(0, 0, unitSize+wallWidth, wallWidth);
  }
  else {
    ofDrawRectangle(0, 0, wallWidth, unitSize+ wallWidth);
  }
  ofPopMatrix();
}

void MazeWall::build() {
  if (!disabled) active = true;
}

void MazeWall::destroy() {
  if (!disabled) active = false;
}
