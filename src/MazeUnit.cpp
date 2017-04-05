#include "MazeUnit.h"

MazeUnit::MazeUnit(int _x, int _y, MazeWall * _walls[]) {
  x = _x;
  y = _y;
  for (int i = 0; i < 4; i++) walls[i] = _walls[i];
}

int MazeUnit::getActiveNeighbourIndex() {
  for (int i = 0; i < 4; i++) {
    if (!walls[i]->disabled && neighbours[i]->active) return i;
  }
  return false;
}

int MazeUnit::getRandomInactiveNeighbourIndex() {
  int count = countInactiveNeighbours();
  if (count == 0) return -1;
  int choice = rand() % count;
  int through = 0;
  for (int i = 0; i < 4; i++) {
    if (!walls[i]->disabled && !neighbours[i]->active) {
      if (through == choice) {
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

int MazeUnit::countActiveNeighbours() {
  int count = 0;
  for (int i = 0; i < 4; i++) {
    if (!walls[i]->disabled && neighbours[i]->active) count++;
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
