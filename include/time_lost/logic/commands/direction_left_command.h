#ifndef DIRECTION_LEFT_COMMAND_H
#define DIRECTION_LEFT_COMMAND_H

#include "../command.h"

namespace time_lost{

namespace logic{

namespace commands{

class DirectionLeftCommand: public Command{
public:
    DirectionLeftCommand() = default;

    void Execute(TimeLost& game) override;

    bool IsEmpty() override;
};

} // commands
} // logic
} // time_lost


#endif // DIRECTION_LEFT_COMMAND_H