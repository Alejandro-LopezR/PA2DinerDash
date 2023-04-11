#pragma once
#include "Animation.h"
#include "Burger.h"
#include "EntityManager.h"
#include "BaseCounter.h"
#include "StoveCounter.h"
class Player: public Entity{

    private:
        int speed = 0; // default speed when not moving
        string facing = "right";
        Animation *chefAnim;
        Burger *burger;
        EntityManager* entityManager;
        bool inFrontOf = false;
    public:
        Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void mousePressed(int, int, int);
        void setFacing(string);
        bool getInFrontOf() {return inFrontOf;}
        BaseCounter* getActiveCounter();
        StoveCounter* getActiveStoveCounter(); // copied getter from base counter to stove counter
        Burger* getBurger(){ return burger;
        }
};