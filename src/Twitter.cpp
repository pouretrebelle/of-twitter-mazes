#include "Twitter.h"

Twitter::Twitter() {
}

void Twitter::setup(Maze * _maze) {
  maze = _maze;
}

void Twitter::saveImage() {
  image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
  image.save("current.jpg", OF_IMAGE_QUALITY_BEST);
}
