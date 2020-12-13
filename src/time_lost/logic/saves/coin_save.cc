#include "time_lost/logic/saves/coin_save.h"

namespace time_lost{

namespace logic{

namespace saves{

CoinSave::CoinSave(types::Position pos, int count, bool on_field, bool can_use):
data{pos, count, on_field, can_use}
{
}

objects::Coin CoinSave::LoadCoin(){
    objects::Coin Coin(data.count, data.pos);
    Coin.SetCanUse(data.can_use);
    Coin.SetOnField(data.on_field);
    return Coin;
}

std::shared_ptr<objects::Item> CoinSave::LoadItem(){
    return LoadCoin().CloneItem();
}

void CoinSave::WriteItem(std::ostream& os){
    os << *this;
}

std::ostream& operator<<(std::ostream& os, CoinSave& save){
    int type = types::SaveType::kCoin;
    os.write((char*)&type, sizeof(int));
    os.write((char*)&save.data, sizeof(CoinSave::Data));
    return os;
}

std::istream& operator>>(std::istream& is, CoinSave& save){
    is.read((char*)&save.data, sizeof(CoinSave::Data));
    if(save.data.pos.x < 0 || save.data.pos.y < 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    if(save.data.count <= 0) throw types::TimeLostException(__FILE__, __LINE__, "Wrong value in save");
    return is;
}

} // saves
} // logic
} // time_lost