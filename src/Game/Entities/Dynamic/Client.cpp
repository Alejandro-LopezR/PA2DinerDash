#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
}
Client::~Client(){
    delete burger;
}
void Client::render(){
    ofSetColor(255,255,255); // keeps burger in original color
    burger->render();
    if (patience >= 1600) {ofSetColor (255,255,255);} // As patience goes down, we lower the values of green and blue so red is more prominent, thus making the client redder
    else if (patience >= 1200) {ofSetColor(255,177,177);}
    else if (patience >= 800) {ofSetColor(255,133,133);}
    else if (patience >= 400) {ofSetColor(255,102,102);}
    else if (patience < 400) {ofSetColor(255,51,51);}
    sprite.draw(x, y, width, height);
    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patience--;
    burger->setY(y);
    if(patience == 0){
        isLeaving = true;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger* burger){
    isLeaving = true;
    return 10;
}