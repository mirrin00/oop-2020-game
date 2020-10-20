#ifndef _H
#define _H

#include "../objects/player.h"
#include "../objects/sword.h"
#include "../objects/coin.h"
#include "../objects/health_potion.h"
#include "../objects/field_iterator.h"
#include "logger.h"
#include <vector>

namespace etu_game{

namespace logic{

class EtuGame{
protected:
    objects::Player player;

    objects::Field& field;

    std::vector<std::shared_ptr<objects::Item>> items;
public:
    EtuGame(int height, int width);

    ~EtuGame();

    objects::Field& GetField();

    objects::Player& GetPlayer();

    void PlayerMove(int h_pos, int w_pos);

    void PlayerInteract();

    void AddItem(objects::Item& item);

    void AddItem(objects::Item&& item);

    std::shared_ptr<objects::Item> GetItem(int index);

    void Start();

    bool IsWin();
};

} // logic
} // etu_game


#endif // _H