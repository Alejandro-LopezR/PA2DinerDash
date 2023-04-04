#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
}
void GameState::tick() {
	restaurant->tick();
	if (restaurant->ofGetLoseCounter() >= 10) {
		setFinished(true);
		setNextState("Lose");
	}
	if (restaurant->ofGetMoney() >= 100){
		setFinished(true);
		setNextState("Win");
	}
}
void GameState::render() {
	restaurant->render();
}

void GameState::keyPressed(int key){
	restaurant->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}