#ifndef FIRST_AID_KIT_H
#define FIRST_AID_KIT_H

#include "item.h"

namespace time_lost{
namespace logic{
namespace saves{
class FirstAidKitSave;
}
}
}

#include "../logic/saves/first_aid_kit_save.h"

namespace time_lost{

namespace objects{

class FirstAidKit: public Item{
private:
    int count;
protected:
    virtual void Notify() override;
public:
    FirstAidKit(int count, types::Position start_pos = {0,0});

    ~FirstAidKit();

    FirstAidKit(const FirstAidKit& hp);

    FirstAidKit& operator=(const FirstAidKit& hp);

    int GetCount();
    
    void SetCount(int new_count);

    virtual void Use(Player& player) override;

    virtual std::shared_ptr<Item> CloneItem() const override;

    std::shared_ptr<logic::saves::FirstAidKitSave> SaveFirstAidKit();

    virtual std::shared_ptr<logic::saves::ItemSaveInterface> SaveItem() override;

    friend std::ostream& operator<<(std::ostream& os, const FirstAidKit& hp);
};

    std::ostream& operator<<(std::ostream& os, const FirstAidKit& hp);

} // objects
} // time_lost


#endif // FIRST_AID_KIT_H