#pragma once
#include "ofMain.h"
#include "MazeUnit.h"
#include "MazeWall.h"
#include "MazePath.h"

class Maze {

public:

  Maze();

  void setup(int _w, int _rows, int _columns, int _margin, int _wallWidth, int _wallBorderRadius, ofColor _wallColor, ofColor _backgroundColor);
  void setupWalls();
  void setupUnits();

  void huntAndKill();
  MazeUnit * hunt();
  void kill(MazeUnit * unit);

  void draw();
  void drawWalls();
  void drawUnits();
  void drawPath();

  int unitsX, unitsY, margin;
  float w, h, size;

  int wallWidth;
  int wallBorderRadius;
  ofColor wallColor;
  ofColor backgroundColor;

  vector<MazeUnit> mazeUnits;
  int** mazeUnitPositions;

  vector<MazeWall> mazeWalls;
  int** mazeWallPositions;

  MazePath mazePath;
  void go(string direction, ofColor color);

  void regenerate();

private:

};