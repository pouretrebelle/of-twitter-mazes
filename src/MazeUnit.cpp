#include "MazeUnit.h"

MazeUnit::MazeUnit(int _x, int _y, MazeWall * left, MazeWall * top, MazeWall * right, MazeWall * bottom) {
  x = _x;
  y = _y;

  walls[0] = left;
  walls[1] = top;
  walls[2] = right;
  walls[3] = bottom;
}

int MazeUnit::countAbleNeighbours() {
  int count = 0;
  for (int i = 0; i < 4; i++) {
    if (!walls[i]->disabled) count++;
  }
  return count;
}

int MazeUnit::countActiveNeighbours() {
  int count = 0;
  for (int i = 0; i < 4; i++) {
    if (!walls[i]->disabled && walls[i]->active) count++;
  }
  return count;
}

int MazeUnit::countInactiveNeighbours() {
  int count = 0;
  for (int i = 0; i < 4; i++) {
    if (!walls[i]->disabled && !walls[i]->active) count++;
  }
  return count;
}
