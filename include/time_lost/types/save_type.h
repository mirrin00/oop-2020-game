#ifndef SAVE_TYPE_H
#define SAVE_TYPE_H

namespace time_lost{

namespace types{

class SaveType{
public:
    enum Type{
        kPlayer, // 0
        kEnemyFind, // 1
        kEnemyFly, // 2
        kEnemyWait, // 3
        kBullets, // 4
        kField, // 5
        kHands, // 6
        kFirstAidKit, // 7
        kSword, // 8
        kTimeLost, // 9
    };
};

} // types
} // time_lost


#endif // SAVE_TYPE_H