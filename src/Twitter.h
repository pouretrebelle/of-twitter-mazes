#pragma once
#include "ofMain.h"
#include "Maze.h"

class Twitter {

public:

  Twitter();

  void setup(Maze * _maze);
  void saveImage();

  ofImage image;
  Maze * maze;

private:

};
