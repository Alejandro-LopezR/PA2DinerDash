#include "Entity.h"
#include "Burger.h"
class Client: public Entity{
    private:
        Burger* burger;
        int originalPatience;
        int patience=2000;
    public:
        Client(int, int, int, int, ofImage, Burger*);
        virtual ~Client();
        void tick();
        void render();
        int serve(Burger*);
        Client* nextClient=nullptr;
        bool isLeaving=false;
        Burger* getBurger() {return burger;} // returns the first Client's burger, used in equals() method
        int price = 0; // used in return to return full price of burger



};