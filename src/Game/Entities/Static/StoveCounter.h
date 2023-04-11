#include "BaseCounter.h"
// Simple inheritance from base counter
class StoveCounter: public BaseCounter {
    private:
        Item *item;

    public:
        StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite);
        Item* getItem();
        void showItem();

};