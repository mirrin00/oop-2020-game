#ifndef DIRECTION_DOWN_COMMAND_H
#define DIRECTION_DOWN_COMMAND_H

#include "../command.h"

namespace time_lost{

namespace logic{

namespace commands{

class DirectionDownCommand: public Command{
public:
    DirectionDownCommand() = default;

    void Execute(TimeLost& game) override;

    bool IsEmpty() override;
};

} // commands
} // logic
} // time_lost


#endif // DIRECTION_DOWN_COMMAND_H