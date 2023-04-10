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
    if (this->getBurger()->equals(burger)) {
        isLeaving = true;
        for (int i = 0; i < (int)burger->getIngredients().size(); i++){
            if (burger->getIngredients()[i]->getName() == "cheese") { // adds 3 dollars if cheese is added to burger
                price += 3;
            }
            if (burger->getIngredients()[i]->getName() == "lettuce") { // adds 2 dollars if lettuce is added
                price += 2;
            }
            if (burger->getIngredients()[i]->getName() == "tomato") { // adds 2 dollars if tomato is added
                price += 2;
            }
            if (burger->getIngredients()[i]->getName() == "patty") { // adds 4 dollars if patty is added
                price += 4;
            }
            if (burger->getIngredients()[i]->getName() == "topBun") { // adds 1 dollar if top bun is added
                price += 1;
            }
            if (burger->getIngredients()[i]->getName() == "bottomBun") { // adds 1 dollar if bottom bun is added
                price += 1;
            }
        }
        return price; // returns final added price
    }
    else if(this->nextClient != nullptr){
        this->nextClient->serve(burger);
    }
    return price = 0;
}