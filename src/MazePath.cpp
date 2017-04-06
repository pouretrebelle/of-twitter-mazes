#include "MazePath.h"

MazePath::MazePath() {
}

void MazePath::setup(vector<MazeUnit> * _mazeUnits, int** _mazeUnitPositions) {
  mazeUnits = _mazeUnits;
  mazeUnitPositions = _mazeUnitPositions;

  // start at the start
  addToPath(0, 0);
}

void MazePath::draw(float unitSize) {
  ofSetColor(ofColor::crimson);
  ofSetLineWidth(10);

  // draw start of path
  ofDrawLine(0, 0.5*unitSize, 0.5*unitSize, 0.5*unitSize);

  // draw each segment of path
  for (int i = 0; i < mazePathUnits.size() - 1; i++) {
    MazeUnit * start = mazePathUnits[i];
    MazeUnit * end = mazePathUnits[i+1];
    ofDrawLine((start->x + 0.5)*unitSize, (start->y + 0.5)*unitSize, (end->x + 0.5)*unitSize, (end->y + 0.5)*unitSize);
  }

  // draw ball at the end of path
  ofSetLineWidth(0);
  MazeUnit * end = mazePathUnits[mazePathUnits.size() - 1];
  ofDrawCircle((end->x + 0.5)*unitSize, (end->y + 0.5)*unitSize, 10);
}

void MazePath::addToPath(int x, int y) {
  mazePathUnits.push_back(&(*mazeUnits)[mazeUnitPositions[x][y]]);
}
