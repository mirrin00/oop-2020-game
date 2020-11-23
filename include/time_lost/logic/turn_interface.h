#ifndef TURN_INTERFACE_H
#define TURN_INTERFACE_H

#include "time_lost.h"

namespace time_lost{

namespace logic{

class TurnInterface{
protected:
    TimeLost& game;
public:
    TurnInterface(TimeLost& _game):game(_game){}

    virtual void Pause() = 0;

    virtual void NextTurn() = 0;

    virtual bool IsPause() = 0;

    virtual bool IsPlayerTurn() = 0;
};

} // logic
} // time_lost


#endif // TURN_INTERFACE_H