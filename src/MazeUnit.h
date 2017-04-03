#pragma once
#include "ofMain.h"
#include "MazeWall.h"

class MazeUnit {

public:

  MazeUnit(int _x, int _y, MazeWall * _walls[], MazeUnit * _neighbours[]);

  int countAbleNeighbours();
  int countActiveNeighbours();
  int countInactiveNeighbours();

  int x, y;
  MazeWall * walls[4];
  MazeUnit * neighbours[4];

private:

};