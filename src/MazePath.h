#pragma once
#include "ofMain.h"
#include "MazeUnit.h"

class MazePath {

public:

  MazePath();

  void setup(vector<MazeUnit> * _mazeUnits, int** _mazeUnitPositions, int _unitsX, int _unitsY);
  void draw(float unitSize);

  void addToPath(int x, int y);
  void travel(int direction);

  int unitsX;
  int unitsY;

  vector<MazeUnit> * mazeUnits;
  int** mazeUnitPositions;
  vector<MazeUnit *> mazePathUnits;
  MazeUnit * MazePath::last();

  bool complete;

private:

};
