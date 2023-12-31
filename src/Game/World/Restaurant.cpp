//
// Created by joshu on 11/3/2020.
//

#include "Restaurant.h"

Player *Restaurant::getPlayer() { return player; }
void Restaurant::setPlayer(Player *player) { this->player = player; }

Restaurant::Restaurant() {
    ofImage decoSheet;
    decoSheet.load("images/sprite.png"); // allows us to use cropFrom function with the decorations available in sprite.png
    chair.cropFrom(decoSheet, 100, 10, 50, 40); // chair
    table.cropFrom(decoSheet, 5, 10, 100, 100); // table
    door.cropFrom(decoSheet, 70, 70, 40, 110); //door
    
    floor.load("images/floor.jpg");
    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/chef.png");
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager);    
    initItems();
    initCounters();
    initClients();
    generateClient();

}
void Restaurant::initItems(){
    ofImage burgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, botBreadImg, topBreadImg, plateImg, fireSpriteSheet, fireImg;
    burgerSpriteSheet.load("images/burger.png");
    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43); // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48); // patty
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39); // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41); // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34); // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51); // plate
    fireSpriteSheet.load("images/fire.png"); // loads fire sprite
    fireImg.cropFrom(fireSpriteSheet, 0, 0 ,1000, 1000); // fire to show that burger will be cooked
    cheese = new Item(cheeseImg, "cheese");
    lettuce = new Item(lettuceImg, "lettuce");
    tomato = new Item(tomatoImg, "tomato");
    burger = new Item(burgerImg, "patty");
    botBread = new Item(botBreadImg, "bottomBun");
    topBread = new Item(topBreadImg, "topBun");
    fire = new Item(fireImg, "fire"); // fire item to use in "cooking" process
}
void Restaurant::initCounters(){
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, lettuceCounterImg, emptyCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet, 224,12,32,43);//stoveTop
    lettuceCounterImg.cropFrom(counterSheet,96,76,32,43);//Vegetables
    emptyCounterImg.cropFrom(counterSheet,0,245,30,43);//Empty
    tomatoCounterImg.cropFrom(counterSheet,96,200,32,48);//fruit basket
    cheeseCounterImg.cropFrom(counterSheet,64,73,32,46);//cheese
    plateCounterImg.cropFrom(counterSheet,0,133,32,50);//plates
    breadCounterImg.cropFrom(counterSheet,0,63,34,56);//buns
    entityManager->addEntity(new BaseCounter(0,yOffset-16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity( new BaseCounter(counterWidth,yOffset-7, counterWidth,108, cheese, cheeseCounterImg));
    entityManager->addEntity(new StoveCounter(counterWidth*2,yOffset, counterWidth, 102, burger, stoveCounterImg)); // changed from BaseCounter class to StoveCounter class
    entityManager->addEntity(new BaseCounter(counterWidth*3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*4,yOffset, counterWidth, 102, nullptr, emptyCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*5, yOffset -10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*6, yOffset-32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*7, yOffset-32, counterWidth, 133, topBread, breadCounterImg));

}
void Restaurant::initClients(){
    ofImage temp;
    temp.load("images/People/Car_Designer3Female.png");
    people.push_back(temp);
    temp.load("images/People/Freedom_Fighter2Male.png");
    people.push_back(temp);
    temp.load("images/People/Hipster.png");
    people.push_back(temp);
    temp.load("images/People/Lawyer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Mad_Scientist3Female.png");
    people.push_back(temp);
    temp.load("images/People/Programmer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Songwriter3Male.png");
    people.push_back(temp);
    temp.load("images/People/Weather_Reporter2Female.png");
    people.push_back(temp);
}
void Restaurant::tick() {
    ticks++;
    if(ticks % 400 == 0){
        generateClient();
    }
    player->tick();
    entityManager->tick();

}


void Restaurant::generateClient(){
    Burger* b = new Burger(72, 100, 50, 25);
    b->addIngredient(botBread);
    burgIngs.push_back(cheese); // Specifically excludes top bun and bottom bun from burgIngs
    burgIngs.push_back(lettuce);
    burgIngs.push_back(tomato);
    burgIngs.push_back(burger);
    float limit = round(ofRandom(1,3)); // chooses random number between 1 and 3
    for (int i = 0; i < limit; i++){ // tells us how many ingredients will be added (1 through 3)
        float randPos = round(ofRandom(0,3)); // chooses random number between 0 and 3 which correlates to vector list position values
        for (int j = randPos; j < 4; j++){ // chooses random ingredient from burgIngs (chhese, lettuce, tomato, or burger)
            b->addIngredient(burgIngs[j]);
            break;
        }
    }
    b->addIngredient(topBread);
    entityManager->addClient(new Client(0, 50, 64, 72,people[ofRandom(8)], b));
}
void Restaurant::render() {
    floor.draw(0,0, ofGetWidth(), ofGetHeight());
    int Ydistance = 0; // Used to seperate the two rows of chairs and tables
    for (int j = 0; j < 2; j++){ // Draws two rows of chairs and tables
        int Xdistance = 0; // Used to seperate the sets of chairs and tables in each row
        for (int i = 0; i < 5; i++){ // Draws 5 sets of one table and two chairs in each row
            chair.draw(175 + Xdistance, 75 + Ydistance, 50, 45); // top chair
            table.draw(150 + Xdistance, 93 + Ydistance, 100, 100); // table
            chair.draw(175 + Xdistance, 160 + Ydistance, 50, 45); // bottom chair
            Xdistance += 125; // Makes it so each set of chairs and tables in each row have a distance of 125 between them
        }
        Ydistance += 175; // Makes it so the rows have a distance of 175 between them
    }
    door.draw(0, -65, 70, 150); // door
    player->render();
    entityManager->render();
    ofSetColor(0, 100, 0);
    ofDrawBitmapString("Money: " + to_string(money), ofGetWidth()/2, 10);
    ofSetColor(256, 256, 256);
}
void Restaurant::serveClient(){
    if(entityManager->firstClient!= nullptr){
        money += entityManager->firstClient->serve(player->getBurger());
    }
}
void Restaurant::keyPressed(int key) {
    player->keyPressed(key);
    if(key == 's'){
        serveClient();
        player->getBurger()->clear(); // deletes player's burger after attempted use
    }
    if (key == 'u'){ // deletes last added ingredient to player's burger
        player->getBurger()->removeIngredient();
    }
    if (key == 'e'){ // makes it so it costs one dollar to add an ingredient to the player's burger
        if (player->getInFrontOf() == true) {
            money -= 1;
        }
    }
}