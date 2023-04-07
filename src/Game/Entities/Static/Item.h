//
// Created by joshu on 11/4/2020.
//
#pragma once

#include "ofMain.h"

class Item {    
public:
    Item(ofImage, string);
    ofImage sprite;
    string name;
    string getName() {return name;} // returns name of ingredients, used in equals method
};
