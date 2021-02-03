#include "time_lost/logic/saves/time_lost_save.h"

#include "time_lost/types/behavior_find.h"
#include "time_lost/types/behavior_fly.h"
#include "time_lost/types/behavior_wait.h"

namespace time_lost{

namespace logic{

namespace saves{

TimeLostSave::TimeLostSave(objects::Player& player, objects::Field& field,
std::list<std::shared_ptr<objects::Item>>& items, 
std::list<std::shared_ptr<objects::Enemy>>& enemys, int step_change):
_step_change(step_change),
_player(player.SavePlayer())
{
    _field = field.SaveField();
    for(auto item:items){
        _items.emplace_back(item->SaveItem());
    }
    for(auto enemy:enemys){
        _enemys.emplace_back(enemy->SaveEnemy());
    }
}

TimeLostSave::TimeLostSave(const TimeLostSave& save){
    _step_change = save._step_change;
    _player = save._player;
    _field = std::move(save._field);
    _items = save._items;
    _enemys = save._enemys;
}

TimeLostSave& TimeLostSave::operator=(const TimeLostSave& save){
    if(&save == this) return *this;
    _step_change = save._step_change;
    _player = save._player;
    _field = std::move(save._field);
    _items = save._items;
    _enemys = save._enemys;
    return *this;
}

TimeLost TimeLostSave::LoadTimeLost(){
    TimeLost time_lost(1,1);
    time_lost.step_change = _step_change;
    time_lost.field = _field.LoadField();
    time_lost.player = _player.LoadPlayer();
    time_lost.items.clear();
    for(auto item:_items){
        //auto i = item->LoadItem();
        //FIXME: Check this
        time_lost.items.emplace_back(item->LoadItem());
    }
    time_lost.enemys.clear();
    for(auto enemy:_enemys){
        switch(enemy->GetSaveType()){
            case types::SaveType::kEnemyFind:
                time_lost.enemys.emplace_back(enemy->LoadEnemy<types::BehaviorFind>());
                break;
            case types::SaveType::kEnemyFly:
                time_lost.enemys.emplace_back(enemy->LoadEnemy<types::BehaviorFly>());
                break;
            case types::SaveType::kEnemyWait:
                time_lost.enemys.emplace_back(enemy->LoadEnemy<types::BehaviorWait>());
                break;
        }
    }
    return time_lost;
}

std::ostream& operator<<(std::ostream& os, TimeLostSave& save){
    int type = types::SaveType::kTimeLost;
    os.write((char*)&type,sizeof(int));
    type = save._step_change;
    os.write((char*)&type,sizeof(int));
    os << (save._player);
    os << save._field;
    type = save._items.size();
    os.write((char*)&type,sizeof(int));
    for(auto item: save._items){
        item->WriteItem(os);
    }
    type = save._enemys.size();
    os.write((char*)&type,sizeof(int));
    for(auto enemy: save._enemys){
        os << *enemy;
    }
    return os;
}

std::istream& operator>>(std::istream& is, TimeLostSave& save){
    int type;
    is.read((char*)&type, sizeof(int));
    if(type != types::SaveType::kTimeLost) throw types::TimeLostException((std::string(__FILE__) + ":" + std::to_string(__LINE__)) + "Reading save: Bad Save");
    is.read((char*)&type, sizeof(int));
    save._step_change = type;
    if(save._step_change <= 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    is.read((char*)&type, sizeof(int));
    if(type != types::SaveType::kPlayer) throw types::TimeLostException((std::string(__FILE__) + ":" + std::to_string(__LINE__)) + "Reading save: Bad Save");
    is >> save._player;
    is.read((char*)&type, sizeof(int));
    if(type != types::SaveType::kField) throw types::TimeLostException((std::string(__FILE__) + ":" + std::to_string(__LINE__)) + "Reading save: Bad Save");
    is >> save._field;
    int size;
    is.read((char*)&size, sizeof(int));
    if(size < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    for(int i=0;i<size;i++){
        is.read((char*)&type, sizeof(int));
        switch(type){
            case types::SaveType::kBullets:
            {
                auto coin = std::make_shared<BulletsSave>();
                is >> *coin;
                save._items.emplace_back(coin);
                break;
            }
            case types::SaveType::kFirstAidKit:
            {
                auto item = std::make_shared<FirstAidKitSave>();
                is >> *item;
                save._items.emplace_back(item);
                break;
            }
            default:
                throw types::TimeLostException((std::string(__FILE__) + ":" + std::to_string(__LINE__)) + "Reading save: Bad Save");
        }
    }
    if(size < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    is.read((char*)&size, sizeof(int));
    for(int i=0;i<size;i++){
        is.read((char*)&type, sizeof(int));
        switch(type){
            case types::SaveType::kEnemyFind:
            {
                auto enemy = std::make_shared<EnemySave>();
                is >> *enemy;
                save._enemys.emplace_back(enemy);
                break;
            }
            case types::SaveType::kEnemyFly:
            {
                auto enemy = std::make_shared<EnemySave>();
                is >> *enemy;
                save._enemys.emplace_back(enemy);
                break;
            }
            case types::SaveType::kEnemyWait:
            {
                auto enemy = std::make_shared<EnemySave>();
                is >> *enemy;
                save._enemys.emplace_back(enemy);
                break;
            }
            default:
                throw types::TimeLostException((std::string(__FILE__) + ":" + std::to_string(__LINE__)) + "Reading save: Bad Save");
        }
    }
    return is;
}

} // saves
} // logic
} // time_lost