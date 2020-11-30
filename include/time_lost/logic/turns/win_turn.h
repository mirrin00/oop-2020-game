#ifndef WIN_TURN_H
#define WIN_TURN_H

#include "../turn_interface.h"

namespace time_lost{

namespace logic{

namespace turns
{
    
class WinTurn: public TurnInterface{
public:
    WinTurn(TimeLost& game);

    void Pause() override;

    void NextTurn() override;
    
    virtual types::Turns::Turn GetTurn() override;
};

} // turns
} // logic
} // time_lost


#endif // WIN_TURN_H