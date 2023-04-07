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
    if (playerBurger->getIngredients().size() == this->getIngredients().size()){ // if this is failed then the burgers are not the same
        if (playerBurger->getIngredients().front()->getName() == "topBread" && this->getIngredients().front()->getName() == "topBread"
        && playerBurger->getIngredients().back()->getName() == "botBread" && this->getIngredients().back()->getName() == "botBread"){ // checks if the first and last ingredients of the target and parameter burgers are the corresponding buns
            std::vector<Item *> playerBurgerCopy(playerBurger->getIngredients()); // gives us vector list of parameter burger
            std::vector<Item *> thisCopy(this->getIngredients()); // gives us vector list of target burger
            for (int i = 1; i < thisCopy.size()-1; i++){
                for (int j = 1; i != j; j++) { // nested for loop is used to verify if each ingredient is the same in both burgers, does not take into account the ingredient in the same position for the same burger (thats why i != j)
                if (playerBurgerCopy[i]->getName() == thisCopy[j]->getName()) {isEqual = true;} // returns true if all ingredients are the same and in the same position as in the other burger but not itself (thats why i != j)
                else {isEqual = false;} // if one ingredient is not the same then it return false
                }
            }
        }
    } return isEqual;  // if any previous if before nested for loop is not met returns false, if nested for loop ends with isEqual being true then returns true
}