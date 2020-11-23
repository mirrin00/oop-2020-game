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
public:
    virtual ~Command() = default;

    virtual void Execute(TimeLost& game) = 0;
};

} // logic
} // time_lost


#endif // COMMAND_H