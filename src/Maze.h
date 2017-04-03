#pragma once
#include "ofMain.h"
#include "MazeUnit.h"
#include "MazeWall.h"

class Maze {

public:

  Maze(int _w, int _rows, int _columns);

  void setupWalls();
  void draw();

  int unitsX, unitsY;
  float w, h, size;

  int wallWidth = 3;

  vector<MazeUnit> mazeUnits;
  int** mazeUnitPositions;

  vector<MazeWall> mazeWalls;
  int** mazeWallPositions;

private:

};