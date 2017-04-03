#include "Maze.h"

Maze::Maze() {
}

void Maze::setup(int _w, int _rows, int _columns) {

  // assign variables
  w = _w * 1.0;
  unitsX = _rows;
  unitsY = _columns;
  size = w / unitsX;
  h = unitsY * size;

  // make a load of walls
  setupWalls();

  // make a load of units that reference those walls
  setupUnits();

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
      if (x == unitsX * 2) disabled = true; // right
      if (y == unitsY) disabled = true; // bottom

      // make that wall!
      MazeWall newWall(floor(x*0.5), y, x % 2, disabled);

      // don't draw the verticals of the bottom row
      if (y == unitsY && x % 2 == 0) newWall.active = false;

      // add to vector and save position
      mazeWalls.push_back(newWall);
      mazeWallPositions[x][y] = y * (unitsX * 2 + 1) + x;
    }
  }
}

void Maze::setupUnits() {

  // initialise mazeUnitPositions 2D array
  mazeUnitPositions = new int*[unitsX];
  for (int x = 0; x < unitsX; x++) {
    mazeUnitPositions[x] = new int[unitsY];
  }

  // initialise mazeWalls
  for (int y = 0; y < unitsY; y++) {
    for (int x = 0; x < unitsX; x++) {

      // get pointers to each of the right walls
      MazeWall * left = &mazeWalls[mazeWallPositions[x * 2][y]];
      MazeWall * top = &mazeWalls[mazeWallPositions[x * 2 + 1][y]];
      MazeWall * right = &mazeWalls[mazeWallPositions[x * 2 + 2][y]];
      MazeWall * bottom = &mazeWalls[mazeWallPositions[x * 2 + 1][y+1]];

      // make that unit!
      MazeUnit newUnit(x, y, left, top, right, bottom);

      // add to vector and save position
      mazeUnits.push_back(newUnit);
      mazeUnitPositions[x][y] = y * unitsX + x;
    }
  }
}

void Maze::draw() {
  ofSetLineWidth(wallWidth);
  for (int i = 0; i < mazeWalls.size(); i++) {
    mazeWalls[i].draw(size);
  }
}
