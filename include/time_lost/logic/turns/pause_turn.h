#ifndef PAUSE_TURN_H
#define PAUSE_TURN_H

#include "../turn_interface.h"
#include "player_turn.h"

namespace time_lost{

namespace logic{

namespace turns
{
    
class PauseTurn: public TurnInterface{
public:
    PauseTurn(TimeLost& game);

    void Pause() override;

    void NextTurn() override;

    bool IsPause() override;

    bool IsPlayerTurn() override;
};

} // turns
} // logic
} // time_lost


#endif // PAUSE_TURN_H