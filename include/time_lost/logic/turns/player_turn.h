#ifndef PLAYER_TURN_H
#define PLAYER_TURN_H

#include "../turn_interface.h"
#include "enemy_turn.h"
#include "pause_turn.h"

namespace time_lost{

namespace logic{

namespace turns
{
    
class PlayerTurn: public TurnInterface{
public:
    PlayerTurn(TimeLost& game);

    void Pause() override;

    void NextTurn() override;
    
    bool IsPause() override;

    bool IsPlayerTurn() override;
};

} // turns
} // logic
} // time_lost


#endif // PLAYER_TURN_H