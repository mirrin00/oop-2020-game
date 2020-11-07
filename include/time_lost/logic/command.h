#ifndef COMMAND_H
#define COMMAND_H

namespace time_lost{
namespace logic{
class TimeLost;
}
}

#include "time_lost.h"

namespace time_lost{

namespace logic{

class Command{
protected:
    TimeLost& game;
public:
    Command(TimeLost& _game):game(_game){}

    virtual void Execute() = 0;
};

} // logic
} // time_lost


#endif // COMMAND_H