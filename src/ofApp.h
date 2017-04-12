#pragma once

#include "ofMain.h"
#include "Maze.h"
#include "Twitter.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);

    Maze maze;
    Twitter twitter;
		
};
