#include "MazeWall.h"

MazeWall::MazeWall(int _x, int _y, bool _vertical, bool _disabled) {
  x = _x;
  y = _y;
  vertical = _vertical;
  disabled = _disabled;
  active = true;
}
