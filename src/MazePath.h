#pragma once
#include "ofMain.h"
#include "MazeUnit.h"
#include "MazePathSegment.h"

class MazePath {

public:

  MazePath();

  void setup(vector<MazeUnit> * _mazeUnits, int** _mazeUnitPositions, int _unitsX, int _unitsY);
  void draw(float unitSize);
  void reset();

  void addToPath(int x, int y, ofColor color);
  void travel(int direction, ofColor color);

  int unitsX;
  int unitsY;

  ofColor pathColor;
  int pathWidth;
  int pathHeadSize;

  vector<MazeUnit> * mazeUnits;
  int** mazeUnitPositions;
  vector<MazePathSegment> mazePathSegments;
  vector<MazeUnit *> mazePathUnits;
  MazeUnit * MazePath::last();

  bool complete;

private:

};
