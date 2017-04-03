#include "MazeUnit.h"

MazeUnit::MazeUnit(int _x, int _y, MazeWall * left, MazeWall * top, MazeWall * right, MazeWall * bottom) {
  x = _x;
  y = _y;

  walls[0] = left;
  walls[1] = top;
  walls[2] = right;
  walls[3] = bottom;
}
