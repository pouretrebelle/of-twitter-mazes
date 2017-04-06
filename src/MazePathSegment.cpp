#include "MazePathSegment.h"

MazePathSegment::MazePathSegment(MazeUnit * _start, MazeUnit * _end) {
  start = _start;
  end = _end;
}

void MazePathSegment::draw(float unitSize, float pathWidth) {
  ofSetLineWidth(pathWidth);
  ofDrawLine((start->x + 0.5)*unitSize, (start->y + 0.5)*unitSize, (end->x + 0.5)*unitSize, (end->y + 0.5)*unitSize);
}
