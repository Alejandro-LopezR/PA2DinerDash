#pragma once

#include "ofMain.h"
#include "MenuState.h"
#include "GameState.h"
#include "LoseState.h" // added so states can exist
#include "WinState.h"

class ofApp : public ofBaseApp{

private:
	State *currentState;
	MenuState *menuState;
	GameState *gameState;
	LoseState *loseState; // added so states can exist
	WinState *winState;
	
	ofSoundPlayer sound;


public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
