//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item) {
    ingredients.push_back(item);
}

void Burger::removeIngredient() {
    if (!ingredients.empty()) {
        ingredients.pop_back();
    }
}

void Burger::render(){
    int counter = 1;
    for (Item* ingredient:ingredients){
        ingredient->sprite.draw(x-5,y-(counter * 10)+55,width*0.70,height*0.70);
        counter++;
    }
}

void Burger::clear(){
    ingredients.empty();
}

bool Burger::equals(Burger* playerBurger){
    std::vector<Item *> playerBurgerCopy(playerBurger->getIngredients()); // gives us vector list of target burger
    std::vector<Item *> thisCopy(this->getIngredients()); //gives us vector list of parameter burger
    for (int i = 0; i < (int)playerBurgerCopy.size(); i++){
        for (int j = 0; j < (int)thisCopy.size(); j++){ // nested for loop goes through every ingredient
            if (playerBurger->getIngredients()[i] == this->getIngredients()[j]) { // checks if current ingredient is in both burgers, returns true if so
                isEqual = true;
                break;
            } 
            else if (playerBurger->getIngredients().size() != this->getIngredients().size()) {return false;} // if not equal size returns false, avoids various bugs in program
        }
    } return isEqual; // final return for function
}