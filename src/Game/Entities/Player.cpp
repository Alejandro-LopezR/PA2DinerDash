#include "Player.h"

Player::Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em) : Entity(x, y, width, height, sprite){

    vector<ofImage> chefAnimframes;
    ofImage temp;
    this->burger = new Burger(ofGetWidth()-110, 100, 100, 50);
    temp.cropFrom(sprite, 30,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 159,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 287, 3,67,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 31,129,66,120);
    chefAnimframes.push_back(temp);
    this->chefAnim = new Animation(50, chefAnimframes);
    this->entityManager = em;
    
}
void Player::tick(){
    chefAnim->tick();
    if(x <= 0){
        speed = 0;
    }else if(x + width >= ofGetWidth()){
        speed = 0;
    }
}

void Player::render(){
    BaseCounter *ac = getActiveCounter();
    if (ac != nullptr) {
        ac->showItem();
    }
    ofSetColor(256, 256, 256);
    ofImage currentFrame = chefAnim->getCurrentFrame();
    if (facing == "left") {
        currentFrame.mirror(false, true);
    }
    currentFrame.draw(x, y, width, height);
    burger->render();
}

void Player::keyPressed(int key){
    if(key == 'e'){
        StoveCounter* asc = getActiveStoveCounter(); // copied process from active counter
        BaseCounter* abc = getActiveCounter();
        if(abc != nullptr){
            Item* item = abc->getItem();
            if(item != nullptr){
                burger->addIngredient(item);
                inFrontOf = true;
            }
            else {
                inFrontOf = false;
            }
        } else if(asc != nullptr){ // copied process from active counter
            Item* item = asc->getItem();
            if(item != nullptr){
                burger->addIngredient(item);
                inFrontOf = true;
            }
            else {
                inFrontOf = false;
            }
        }
    }
    if(key == OF_KEY_LEFT) {
        if (x > 0) {
            x -= 15;
            facing = "left";
        }
    }
    if(key == OF_KEY_RIGHT) {
        if (x + width < ofGetWidth()) {
            x += 15;
            facing = "right";
        }
    }
}
BaseCounter* Player::getActiveCounter(){
    for(Entity* e:entityManager->entities){
        BaseCounter* c = dynamic_cast<BaseCounter*>(e);
        if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}

StoveCounter* Player::getActiveStoveCounter(){ // copied getter for active counter
    for(Entity* e:entityManager->entities){
        StoveCounter* c = dynamic_cast<StoveCounter*>(e);
        if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}

void Player::keyReleased(int key) {
}
void Player::mousePressed(int x, int y, int button) {
}

void Player::setFacing(string facing){ this->facing = facing; }