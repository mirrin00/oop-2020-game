#ifndef LOSE_TURN_H
#define LOSE_TURN_H

#include "../turn_interface.h"

namespace time_lost{

namespace logic{

namespace turns
{
    
class LoseTurn: public TurnInterface{
public:
    LoseTurn(TimeLost& game);

    void Pause() override;

    void NextTurn() override;
    
    virtual types::Turns::Turn GetTurn() override;
};

} // turns
} // logic
} // time_lost


#endif // LOSE_TURN_H