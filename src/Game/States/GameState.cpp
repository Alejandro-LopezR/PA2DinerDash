#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
}
void GameState::tick() {
	restaurant->tick(); 
	if (restaurant->ofGetLoseCounter() >= 10) { // when 10 clients leave, lose state activated
		setFinished(true);
		setNextState("Lose");
	}
	if (restaurant->ofGetMoney() >= 100){ // when money reaches 100, win state activated (good luck)
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