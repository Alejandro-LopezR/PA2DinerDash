#pragma once

#include "Entity.h"
#include "Client.h"

class EntityManager {
private:
	int loseCounter = 0;

public:
	Client* firstClient;
	int ofGetLoseNum() {return loseCounter;}
	void tick();
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void removeLeavingClients();
	std::vector<Entity*> entities;
};