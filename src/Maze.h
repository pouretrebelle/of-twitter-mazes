#pragma once
#include "ofMain.h"
#include "MazeUnit.h"
#include "MazeWall.h"

class Maze {

public:

  Maze();

  void setup(int _w, int _rows, int _columns);
  void setupWalls();
  void setupUnits();
  void draw();

  int unitsX, unitsY;
  float w, h, size;

  int wallWidth = 10;

  vector<MazeUnit> mazeUnits;
  int** mazeUnitPositions;

  vector<MazeWall> mazeWalls;
  int** mazeWallPositions;

private:

};