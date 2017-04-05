#include "MazeUnit.h"

MazeUnit::MazeUnit(int _x, int _y, MazeWall * _walls[]) {
  x = _x;
  y = _y;
  for (int i = 0; i < 4; i++) walls[i] = _walls[i];
}

int MazeUnit::countAbleWalls() {
  int count = 0;
  for (int i = 0; i < 4; i++) {
    if (!walls[i]->disabled) count++;
  }
  return count;
}

int MazeUnit::countBuiltWalls() {
  int count = 0;
  for (int i = 0; i < 4; i++) {
    if (walls[i]->active) count++;
  }
  return count;
}

int MazeUnit::countDestroyedWalls() {
  int count = 0;
  for (int i = 0; i < 4; i++) {
    if (!walls[i]->disabled && !walls[i]->active) count++;
  }
  return count;
}

int MazeUnit::getActiveNeighbourIndex() {
  for (int i = 0; i < 4; i++) {
    if (neighbours[i] && neighbours[i]->active) return i;
  }
  return false;
}

int MazeUnit::getRandomInactiveNeighbourIndex() {
  int count = countInactiveNeighbours();
  if (count == 0) return false;
  int choice = rand() % count;
  int through = 0;
  for (int i = 0; i < 4; i++) {
    if (neighbours[i]) {
      if (through == choice && !walls[i]->disabled) {
        return i;
      }
      through++;
    }
  }
  return -1;
}

int MazeUnit::countInactiveNeighbours() {
  int count = 0;
  for (int i = 0; i < 4; i++) {
    if (!walls[i]->disabled && !neighbours[i]->active) count++;
  }
  return count;
}

void MazeUnit::activate() {
  active = true;
}

void MazeUnit::deactivate() {
  active = false;
}

void MazeUnit::draw(float unitSize) {
  if (!active) return;
  ofDrawRectangle(x*unitSize, y*unitSize, unitSize, unitSize);
}
