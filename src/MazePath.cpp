#include "MazePath.h"

MazePath::MazePath() {
  complete = false;
  pathColor = 0x6f767b;
  originalPathColor = pathColor;
  pathWidth = 6;
  pathHeadSize = 14;
}

void MazePath::setup(vector<MazeUnit> * _mazeUnits, int** _mazeUnitPositions, int _unitsX, int _unitsY) {
  mazeUnits = _mazeUnits;
  mazeUnitPositions = _mazeUnitPositions;

  unitsX = _unitsX;
  unitsY = _unitsY;

  // start at the start
  addToPath(0, 0, pathColor);
}

void MazePath::draw(float unitSize) {
  ofSetColor(pathColor);
  ofSetLineWidth(pathWidth);

  // draw start of path
  ofDrawLine(-unitSize, 0.5*unitSize, 0.5*unitSize, 0.5*unitSize);

  // draw end of path if it's finished
  if (complete) {
    // set the colour to the last segment
    ofSetColor(mazePathSegments[mazePathSegments.size() - 1].color);
    ofDrawLine((unitsX - 0.5)*unitSize, (unitsY - 0.5)*unitSize, (unitsX+1)*unitSize, (unitsY - 0.5)*unitSize);
  }

  ofSetLineWidth(0);
  // draw each segment of path
  for (int i = 0; i < mazePathSegments.size(); i++) {
    mazePathSegments[i].draw(unitSize, pathWidth);
  }

  // draw ball at the end of path
  if (!complete) {
    ofSetLineWidth(0);
    MazeUnit * end = last();
    ofDrawCircle((end->x + 0.5)*unitSize, (end->y + 0.5)*unitSize, pathHeadSize*0.5);
  }
}

void MazePath::reset() {
  complete = false;
  pathColor = originalPathColor;
  mazePathSegments.clear();
}

void MazePath::addToPath(int x, int y, ofColor color) {
  // get the next unit from the x and y
  MazeUnit * next = &(*mazeUnits)[mazeUnitPositions[x][y]];
  // make segment out of previous end and next
  MazePathSegment segment(last(), next, color);
  // add to vector
  mazePathSegments.push_back(segment);

  // if it's the first addition, change the path color
  if (mazePathSegments.size() == 2) {
    pathColor.set(mazePathSegments[1].color);
  }
}

MazeUnit * MazePath::last() {
  // if there are segments
  if (mazePathSegments.size() > 0) {
    // return the 'end' of the last one
    return mazePathSegments[mazePathSegments.size() - 1].end;
  }
  // otherwise return the origin
  return &(*mazeUnits)[0];
}

void MazePath::travel(int direction, ofColor color) {
  // don't move if the path is complete
  if (complete) return;

  // get the end of the line
  MazeUnit * current = last();
  bool hitJunction = false;

  // move until you hit a wall
  while (!current->walls[direction]->disabled && !current->walls[direction]->active && !hitJunction) {
    current = current->neighbours[direction];

    // if the new unit has fewer than 2 walls then you've hit a junction and should stop moving
    if (current->countWalls() != 2) {
      hitJunction = true;
    }
  }
  // if it has moved, add it to the path
  if (current != last()) {
    addToPath(current->x, current->y, color);
  }

  // if the current unit is the last one on the grid the maze is complete!
  if (current->x == unitsX-1 && current->y == unitsY-1 && direction == 2) {
    complete = true;
  }
}
