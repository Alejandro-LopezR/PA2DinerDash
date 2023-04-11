#include "StoveCounter.h"
// simple inheritance from base counter
StoveCounter::StoveCounter(int x, int y, int width, int height,Item* item, ofImage sprite) : BaseCounter(x, y, width, height, item, sprite){
    this->item = item;
}

Item* StoveCounter::getItem(){
    return item;
}

void StoveCounter::showItem(){
    if (item != nullptr){
        item->sprite.draw(x+width/2 -25, y-30, 50, 30);
    }
}
