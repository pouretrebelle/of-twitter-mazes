#include "MazePathSegment.h"

MazePathSegment::MazePathSegment(MazeUnit * _start, MazeUnit * _end) {
  start = _start;
  end = _end;
}

void MazePathSegment::draw(float unitSize, float pathWidth) {
  // always start with the top/left side
  // to avoid complication of negative w/h
  if (start->x > end->x || start->y > end->y) {
    ofDrawRectangle((end->x + 0.5)*unitSize - pathWidth*0.5,
                    (end->y + 0.5)*unitSize - pathWidth*0.5,
                    (start->x - end->x)*unitSize + pathWidth,
                    (start->y - end->y)*unitSize + pathWidth);
  }
  else {
    ofDrawRectangle((start->x + 0.5)*unitSize - pathWidth*0.5,
                    (start->y + 0.5)*unitSize - pathWidth*0.5,
                    (end->x - start->x)*unitSize + pathWidth,
                    (end->y - start->y)*unitSize + pathWidth);
  }
}
