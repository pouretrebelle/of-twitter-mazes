#pragma once
#include "ofMain.h"
#include "MazeUnit.h"

class MazePathSegment {

public:

  MazePathSegment(MazeUnit * _start, MazeUnit * _end);

  void draw(float unitSize, float pathWidth);

  MazeUnit * start;
  MazeUnit * end;

private:

};
