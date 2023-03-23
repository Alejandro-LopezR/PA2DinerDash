#include "MenuState.h"

MenuState::MenuState() {
	string text = "Start";
	startButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 64, 50, "Start");
}
void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}
void MenuState::render() {
	ofSetBackgroundColor(230, 230, 250);
	startButton->render();
	string e = "Press 'e' to pick up ingredients when in front of the counter";
	ofDrawBitmapString("Press 'e' to pick up ingredients when in front of the counter", ofGetWidth()/2 - e.length()*3.5, ofGetHeight()/2);
	string s = "Press 's' to serve client";
	ofDrawBitmapString("Press 's' to serve client", ofGetWidth()/2 - s.length()*3.5, ofGetHeight()/2 + 25);


}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}