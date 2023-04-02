#include "LoseState.h"
#include "State.h"

LoseState::LoseState() {
    gameOver.load("images/Game-Over.jpg");
}
void LoseState::tick() {
}
void LoseState::render() {
    gameOver.draw(0,0, ofGetWidth(), ofGetHeight());
}

void LoseState::keyPressed(int key){
}

void LoseState::mousePressed(int x, int y, int button){
}

void LoseState::keyReleased(int key){
}

void LoseState::reset(){
	setFinished(false);
	setNextState("");
}
