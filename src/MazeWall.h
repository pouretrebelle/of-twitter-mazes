#pragma once
#include "ofMain.h"

class MazeWall {

public:

  MazeWall(int _x, int _y, bool _vertical, bool _disabled);

  int x, y;
  bool vertical, active, disabled;

private:

};
