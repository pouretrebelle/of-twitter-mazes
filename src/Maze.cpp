#include "Maze.h"

Maze::Maze(int _w, int _rows, int _columns) {

  // assign variables
  w = _w * 1.0;
  unitsX = _rows;
  unitsY = _columns;
  size = w / x;
  h = y * size;

  // make a load of walls
  setupWalls();

  // make a load of tiles that reference those walls

  // use algorithm to carve walls
}

void Maze::setupWalls() {

  // initialise mazeWallPositions 2D array
  // x is double for top and left walls for each unit
  // both are +1 for the rightmost and bottommost edges
  mazeWallPositions = new int*[(unitsX * 2 + 1)];
  for (int x = 0; x < (unitsX * 2 + 1); x++) {
    mazeWallPositions[x] = new int[(unitsY + 1)];
  }

  // initialise mazeWalls
  for (int y = 0; y < (unitsY + 1); y++) {
    for (int x = 0; x < (unitsX * 2 + 1); x++) {

      // disable all the edge walls
      bool disabled = false;
      if (x == 0) disabled = true; // left
      if (y == 0 && x % 2 == 1) disabled = true; // top
      if (x > unitsX * 2) disabled = true; // right
      if (y > unitsY) disabled = true; // bottom

      MazeWall newWall(floor(x*0.5), y, x % 2, disabled);
      mazeWalls.push_back(newWall);
      mazeWallPositions[x][y] = y * (unitsX * 2 + 1) + x;
    }
  }
}

void Maze::draw() {

}
