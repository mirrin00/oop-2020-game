#ifndef DIRECTION_UP_COMMAND_H
#define DIRECTION_UP_COMMAND_H

#include "../command.h"

namespace time_lost{

namespace logic{

namespace commands{

class DirectionUpCommand: public Command{
public:
    DirectionUpCommand() = default;

    void Execute(TimeLost& game) override;

    bool IsEmpty() override;
};

} // commands
} // logic
} // time_lost


#endif // DIRECTION_UP_COMMAND_H