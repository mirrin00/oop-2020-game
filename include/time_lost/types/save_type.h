#ifndef SAVE_TYPE_H
#define SAVE_TYPE_H

namespace time_lost{

namespace types{

class SaveType{
public:
    enum Type{
        kPlayer,
        kEnemyFind,
        kEnemyFly,
        kEnemyWait,
        kBullets,
        kField,
        kFirstAidKit,
        kTimeLost,
    };
};

} // types
} // time_lost


#endif // SAVE_TYPE_H