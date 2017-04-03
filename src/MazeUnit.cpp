#include "MazeUnit.h"

MazeUnit::MazeUnit(int _x, int _y, MazeWall * _walls[], MazeUnit * _neighbours[]) {
  x = _x;
  y = _y;
  for (int i = 0; i < 4; i++) walls[i] = _walls[i];
  for (int i = 0; i < 4; i++) {
    neighbours[i] = _neighbours[i];
  }
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
