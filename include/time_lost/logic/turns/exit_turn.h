#ifndef EXIT_TURN_H
#define EXIT_TURN_H

#include "../turn_interface.h"

namespace time_lost{

namespace logic{

namespace turns
{
    
class ExitTurn: public TurnInterface{
public:
    ExitTurn(TimeLost& game);

    void Pause() override;

    void NextTurn() override;
    
    virtual types::Turns::Turn GetTurn() override;
};

} // turns
} // logic
} // time_lost


#endif // EXIT_TURN_H