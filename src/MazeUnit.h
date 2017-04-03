#pragma once
#include "ofMain.h"
#include "MazeWall.h"

class MazeUnit {

public:

  MazeUnit(int _x, int _y, MazeWall * left, MazeWall * top, MazeWall * right, MazeWall * bottom);

  int countAbleNeighbours();
  int countActiveNeighbours();
  int countInactiveNeighbours();

  int x, y;
  MazeWall * walls[4];

private:

};