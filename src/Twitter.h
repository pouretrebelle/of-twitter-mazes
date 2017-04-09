#pragma once
#include "ofMain.h"
#include "Maze.h"

#include "ofxHTTP.h"
#include "ofxJSON.h"

class Twitter {

public:

  Twitter();

  void setup(Maze * _maze);

  Maze * maze;

private:

};
