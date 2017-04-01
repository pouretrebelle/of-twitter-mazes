#pragma once
#include "ofMain.h"

class Maze {

public:

  Maze(int _w, int _rows, int _columns);

  void draw();

  int x, y;
  float w, h, size;

  int wallWidth = 3;

private:

};