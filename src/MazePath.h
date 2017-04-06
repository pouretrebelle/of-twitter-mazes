#pragma once
#include "ofMain.h"
#include "MazeUnit.h"

class MazePath {

public:

  MazePath();

  void setup(vector<MazeUnit> * _mazeUnits, int** _mazeUnitPositions);
  void draw(float unitSize);

  void addToPath(int x, int y);

  vector<MazeUnit> * mazeUnits;
  int** mazeUnitPositions;
  vector<MazeUnit *> mazePathUnits;

private:

};
