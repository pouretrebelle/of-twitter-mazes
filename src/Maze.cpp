#include "Maze.h"

Maze::Maze() {
}

void Maze::setup(int _w, int _rows, int _columns, int _wallWidth, int _wallBorderRadius, ofColor _wallColor, ofColor _backgroundColor) {

  // assign variables
  w = _w * 1.0;
  unitsX = _rows;
  unitsY = _columns;
  size = w / unitsX;
  h = unitsY * size;
  wallWidth = _wallWidth;
  wallBorderRadius = _wallBorderRadius;
  wallColor = _wallColor;
  backgroundColor = _backgroundColor;

  // make a load of walls
  setupWalls();

  // make a load of units that reference those walls
  setupUnits();

  // use algorithm to carve walls
  huntAndKill();
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

  // open up the start of the maze
  mazeWalls[0].active = false;
  // open up the end of the maze
  mazeWalls[mazeWallPositions[unitsX*2][unitsY-1]].active = false;
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
      MazeWall * newUnitWalls[4] = { left, top, right, bottom };

      // make that unit!
      MazeUnit newUnit(x, y, newUnitWalls);

      // add to vector and save position
      mazeUnitPositions[x][y] = y * unitsX + x;
      mazeUnits.push_back(newUnit);
    }
  }

  // add neighbours to mazeWalls
  // must happen after they're all initialised
  for (int y = 0; y < unitsY; y++) {
    for (int x = 0; x < unitsX; x++) {
      MazeUnit * newUnitNeighbours[4];
      if (x > 0) newUnitNeighbours[0] = &mazeUnits[mazeUnitPositions[x - 1][y]]; // left
      if (y > 0) newUnitNeighbours[1] = &mazeUnits[mazeUnitPositions[x][y - 1]]; // top
      if (x < unitsX - 1) newUnitNeighbours[2] = &mazeUnits[mazeUnitPositions[x + 1][y]]; // right
      if (y < unitsY - 1) newUnitNeighbours[3] = &mazeUnits[mazeUnitPositions[x][y + 1]]; // bottom

      // loop and assign them
      for (int i = 0; i < 4; i++) {
        mazeUnits[mazeUnitPositions[x][y]].neighbours[i] = newUnitNeighbours[i];
      }
    }
  }
}


void Maze::huntAndKill() {
  MazeUnit * startUnit;
  startUnit = &mazeUnits[mazeUnitPositions[unitsX/2][unitsY/2]];

  while (startUnit != false) {
    kill(startUnit);
    startUnit = hunt();
  }
  // reset activity of tiles
  for (int i = 0; i < mazeUnits.size(); i++) {
    mazeUnits[i].active = false;
  }
}

void Maze::kill(MazeUnit * unit) {

  unit->activate();

  // remove an active edge
  MazeWall * prevEdge = unit->walls[unit->getActiveNeighbourIndex()];
  if (prevEdge) prevEdge->destroy();

  // find a next tile
  int nextIndex = unit->getRandomInactiveNeighbourIndex();
  MazeUnit * nextUnit;
  while (nextIndex != -1) {
    nextUnit = unit->neighbours[nextIndex];
    nextUnit->activate();
    unit->walls[nextIndex]->destroy();
    unit = nextUnit;
    nextIndex = unit->getRandomInactiveNeighbourIndex();
  }
}

MazeUnit * Maze::hunt() {
  for (int y = 0; y < unitsY; y++) {
    for (int x = 0; x < unitsX; x++) {
      MazeUnit * unit = &mazeUnits[mazeUnitPositions[x][y]];
      if (!unit->active && unit->countActiveNeighbours() > 0) {
        return unit;
      }
    }
  }
  return false;
}

void Maze::drawWalls() {
  //ofSetLineWidth(0);
  //ofSetColor(wallColor);
  //for (int i = 0; i < mazeWalls.size(); i++) {
  //  mazeWalls[i].draw(size, wallWidth);
  //}

  // instead of drawing walls we draw each unit and connect them

  // draw background rectangle
  ofSetColor(wallColor);
  ofDrawRectangle(-wallWidth / 2, -wallWidth / 2, w + wallWidth, h + wallWidth);

  ofSetColor(backgroundColor);
  for (int i = 0; i < mazeUnits.size(); i++) {
    MazeUnit * unit = &mazeUnits[i];
    // draw the center of the unit
    ofDrawRectRounded(unit->x*size+wallWidth*0.5, unit->y*size+wallWidth*0.5, size-wallWidth, size-wallWidth, wallBorderRadius);
    // connect them horizontally
    if (!unit->walls[2]->disabled && !unit->walls[2]->active) {
      ofDrawRectangle((unit->x + 0.5)*size, unit->y*size + wallWidth*0.5, size, size - wallWidth);
    }
    // connect them vertically
    if (!unit->walls[3]->disabled && !unit->walls[3]->active) {
      ofDrawRectangle(unit->x*size + wallWidth*0.5, (unit->y+0.5)*size, size - wallWidth, size);
    }
  }

}

void Maze::drawUnits() {
  for (int i = 0; i < mazeUnits.size(); i++) {
    mazeUnits[i].draw(size);
  }
}
