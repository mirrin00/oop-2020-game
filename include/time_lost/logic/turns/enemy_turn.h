#ifndef ENEMY_TURN_H
#define ENEMY_TURN_H

#include "../turn_interface.h"
#include "player_turn.h"

namespace time_lost{

namespace logic{

namespace turns
{
    
class EnemyTurn: public TurnInterface{
public:
    EnemyTurn(TimeLost& game);

    void Pause() override;

    void NextTurn() override;

    virtual types::Turns::Turn GetTurn() override;
};

} // turns
} // logic
} // time_lost


#endif // ENEMY_TURN_H