#ifndef HEALTH_POTION_SAVE_H
#define HEALTH_POTION_SAVE_H

namespace time_lost{

namespace objects{
class FirstAidKit;
}
}

#include "item_save_interface.h"
#include "../../objects/first_aid_kit.h"
#include "../../types/save_type.h"

namespace time_lost{

namespace logic{

namespace saves{

class FirstAidKitSave: public ItemSaveInterface{
private:
    struct Data{
        types::Position pos;
        
        int count;

        bool on_field;
    };

    Data data;
public:
    FirstAidKitSave() = default;

    FirstAidKitSave(types::Position pos, int count, bool on_field);

    ~FirstAidKitSave();

    objects::FirstAidKit LoadFirstAidKit();

    std::shared_ptr<objects::Item> LoadItem() override;

    virtual void WriteItem(std::ostream& os) override;

    friend std::ostream& operator<<(std::ostream& os, FirstAidKitSave& save);

    friend std::istream& operator>>(std::istream& is, FirstAidKitSave& save);
};

std::ostream& operator<<(std::ostream& os, FirstAidKitSave& save);

std::istream& operator>>(std::istream& is, FirstAidKitSave& save);

} // saves
} // logic
} // time_lost


#endif // HEALTH_POTION_SAVE_H