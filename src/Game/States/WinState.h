#pragma once
// copied menu state structure
#include "State.h"


class WinState: public State{
    public: 
        WinState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);

        ofImage Win; // when win state activated shows this image
};