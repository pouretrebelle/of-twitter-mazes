#include "Maze.h"

Maze::Maze(int _w, int _rows, int _columns) {

  // assign variables
  w = _w * 1.0;
  unitsX = _rows;
  unitsY = _columns;
  size = w / x;
  h = y * size;

  // make a load of walls

  // make a load of tiles that reference those walls

  // use algorithm to carve walls
}

void Maze::draw() {

}
