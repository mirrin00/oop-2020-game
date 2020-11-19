#ifndef EMPTY_COMMAND_H
#define EMPTY_COMMAND_H

#include "../command.h"

namespace time_lost{

namespace logic{

namespace commands{

class EmptyCommand: public Command{
public:
    EmptyCommand() = default;

    void Execute(TimeLost& game) override{};
};

} // commands
} // logic
} // time_lost


#endif // EMPTY_COMMAND_H