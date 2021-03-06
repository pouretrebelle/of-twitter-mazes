#pragma once
#include "ofMain.h"

class MazeWall {

public:

  MazeWall(int _x, int _y, bool _vertical, bool _disabled);

  void draw(float unitSize, int wallWidth);
  void build();
  void destroy();

  int x, y;
  bool horizontal, active, disabled;

private:

};
