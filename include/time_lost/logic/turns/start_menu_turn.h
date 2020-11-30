#ifndef START_MENU_TURN_H
#define START_MENU_TURN_H

#include "../turn_interface.h"
#include "player_turn.h"

namespace time_lost{

namespace logic{

namespace turns
{
    
class StartMenuTurn: public TurnInterface{
public:
    StartMenuTurn(TimeLost& game);

    void Pause() override;

    void NextTurn() override;

    virtual types::Turns::Turn GetTurn() override;
};

} // turns
} // logic
} // time_lost


#endif // START_MENU_TURN_H