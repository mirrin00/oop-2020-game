#ifndef TURNS_H
#define TURNS_H

namespace time_lost{

namespace types{

class Turns{
public:
    enum Turn{
        kPlayer,
        kEnemy,
        kPause,
        kStartMenu,
        kExit,
        kWin,
        kLose,
    };
};

} // types
} // time_lost


#endif // TURNS_H