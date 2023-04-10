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
    ingredients.clear();
}

bool Burger::equals(Burger* playerBurger){
    std::vector<Item *> playerBurgerCopy(playerBurger->getIngredients()); // gives us vector list of target burger
    std::vector<Item *> thisCopy(this->getIngredients()); //gives us vector list of parameter burger
    for (int i = 1; i < (int)playerBurgerCopy.size()-1; i++){
        for (int j = 1; j < (int)thisCopy.size()-1; j++){ // nested for loop goes through every ingredient
            if (playerBurger->getIngredients().size() != this->getIngredients().size()) {return false;} // if not equal size returns false, avoids various bugs in program
            else if (playerBurger->getIngredients()[i] == this->getIngredients()[j]) { // checks if current ingredient is in both burgers, returns true if so
                isEqual = true;
                break;
            }
        }
    } return isEqual; // final return for function
}