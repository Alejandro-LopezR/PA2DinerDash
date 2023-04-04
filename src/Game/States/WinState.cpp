#include "WinState.h"
#include "State.h"

WinState::WinState() {
    Win.load("images/Win.jpg");
}
void WinState::tick() {
}
void WinState::render() {
    Win.draw(0,0, ofGetWidth(), ofGetHeight());
}

void WinState::keyPressed(int key){
}

void WinState::mousePressed(int x, int y, int button){
}

void WinState::keyReleased(int key){
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
}