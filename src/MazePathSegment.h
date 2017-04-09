#pragma once
#include "ofMain.h"
#include "MazeUnit.h"

class MazePathSegment {

public:

  MazePathSegment(MazeUnit * _start, MazeUnit * _end, ofColor _color);

  void draw(float unitSize, float pathWidth);

  ofColor color;
  MazeUnit * start;
  MazeUnit * end;

private:

};
