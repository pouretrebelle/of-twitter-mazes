#pragma once
#include "ofMain.h"
#include "MazeUnit.h"
#include "MazeWall.h"

class Maze {

public:

  Maze();

  void setup(int _w, int _rows, int _columns, int _wallWidth, ofColor _wallColor);
  void setupWalls();
  void setupUnits();

  void huntAndKill();
  MazeUnit * hunt();
  void kill(MazeUnit * unit);

  void drawWalls();
  void drawUnits();

  int unitsX, unitsY;
  float w, h, size;

  int wallWidth;
  ofColor wallColor;

  vector<MazeUnit> mazeUnits;
  int** mazeUnitPositions;

  vector<MazeWall> mazeWalls;
  int** mazeWallPositions;

private:

};