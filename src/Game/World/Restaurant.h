//
// Created by joshu on 11/3/2020.
//
#pragma once

#include "BaseCounter.h"
#include "EntityManager.h"
#include "Player.h"
#include "ofMain.h"


class Restaurant {
    private:
        Player* player;
        EntityManager* entityManager;
        int ticks=0;
        std::vector<ofImage> people;
        int money =0;

    public:
        Restaurant();
        int ofGetMoney() {return money;}
        int ofGetLoseCounter() {return entityManager->ofGetLoseNum();}
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* botBread;
        Item* topBread;
        Item* fire; // declaration of fire item for "cooking" burger
        vector <Item *> burgIngs; // Used for adding random ingredients
        ofImage floor;
        ofImage table; //Used for drawing tables
        ofImage chair; //Used for drawing chairs
        ofImage door; // Used for drawing door
        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
};
