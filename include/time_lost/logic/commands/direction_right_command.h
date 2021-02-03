#ifndef DIRECTION_RIGHT_COMMAND_H
#define DIRECTION_RIGHT_COMMAND_H

#include "../command.h"

namespace time_lost{

namespace logic{

namespace commands{

class DirectionRightCommand: public Command{
public:
    DirectionRightCommand() = default;

    void Execute(TimeLost& game) override;

    bool IsEmpty() override;
};

} // commands
} // logic
} // time_lost


#endif // DIRECTION_RIGHT_COMMAND_H