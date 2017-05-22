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

    ofColor color;
    vector<ofColor> colors = {
      ofColor::coral,
      ofColor::cadetBlue,
      ofColor::gold,
      ofColor::greenYellow,
      ofColor::orange,
      ofColor::deepPink,
      ofColor::fireBrick,
      ofColor::paleVioletRed,
      ofColor::mediumVioletRed,
      ofColor::darkorange,
      ofColor::orangeRed,
      ofColor::orchid,
      ofColor::tomato,
      ofColor::cornflowerBlue,
      ofColor::forestGreen,
      ofColor::lightCoral,
      ofColor::mediumSpringGreen,
      ofColor::teal,
      ofColor::seaGreen,
      ofColor::dodgerBlue,
      ofColor::powderBlue,
    };

    Maze maze;
    Twitter twitter;
		
};
