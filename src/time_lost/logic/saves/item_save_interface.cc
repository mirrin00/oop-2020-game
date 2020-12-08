#include "time_lost/logic/saves/item_save_interface.h"

namespace time_lost{

namespace logic{

namespace saves{

std::ostream& operator<<(std::ostream& os, ItemSaveInterface& save){
    save.WriteItem(os);
    return os;
}

}
}
}