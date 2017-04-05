#pragma once
#include "ofMain.h"
#include "MazeWall.h"

class MazeUnit {

public:

  MazeUnit(int _x, int _y, MazeWall * _walls[]);

  void draw(float unitSize);
  void activate();
  void deactivate();

  int countAbleNeighbours();
  int countActiveNeighbours();
  int countInactiveNeighbours();

  int x, y;
  MazeWall * walls[4];
  MazeUnit * neighbours[4];

  bool active = false;

private:

};
