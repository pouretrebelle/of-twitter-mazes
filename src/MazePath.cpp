#include "MazePath.h"

MazePath::MazePath() {
  complete = false;
}

void MazePath::setup(vector<MazeUnit> * _mazeUnits, int** _mazeUnitPositions, int _unitsX, int _unitsY) {
  mazeUnits = _mazeUnits;
  mazeUnitPositions = _mazeUnitPositions;

  unitsX = _unitsX;
  unitsY = _unitsY;

  // start at the start
  addToPath(0, 0);
}

void MazePath::draw(float unitSize) {
  ofSetColor(ofColor::crimson);
  ofSetLineWidth(10);

  // draw start of path
  ofDrawLine(0, 0.5*unitSize, 0.5*unitSize, 0.5*unitSize);

  // draw each segment of path
  for (int i = 0; i < mazePathSegments.size(); i++) {
    mazePathSegments[i].draw(unitSize, 10);
  }

  // draw end of path if it's finished
  if (complete) {
    ofDrawLine((unitsX-0.5)*unitSize, (unitsY-0.5)*unitSize, unitsX*unitSize, (unitsY-0.5)*unitSize);
  }

  // draw ball at the end of path
  if (!complete) {
    ofSetLineWidth(0);
    MazeUnit * end = last();
    ofDrawCircle((end->x + 0.5)*unitSize, (end->y + 0.5)*unitSize, 10);
  }
}

void MazePath::addToPath(int x, int y) {
  // get the next unit from the x and y
  MazeUnit * next = &(*mazeUnits)[mazeUnitPositions[x][y]];
  // make segment out of previous end and next
  MazePathSegment segment(last(), next);
  // add to vector
  mazePathSegments.push_back(segment);
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

void MazePath::travel(int direction) {
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
    addToPath(current->x, current->y);
  }

  // if the current unit is the last one on the grid the maze is complete!
  if (current->x == unitsX-1 && current->y == unitsY-1) {
    complete = true;
  }
}
