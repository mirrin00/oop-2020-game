#include "time_lost/logic/time_lost.h"

#include "time_lost/logic/turns/start_menu_turn.h"
#include "time_lost/logic/turns/win_turn.h"
#include "time_lost/logic/turns/lose_turn.h"
#include "time_lost/logic/turns/pause_turn.h"
#include "time_lost/logic/save_reader.h"
#include "time_lost/logic/save_writer.h"
#include "time_lost/logic/saves/time_lost_save.h"


namespace time_lost{

namespace logic{

TimeLost::TimeLost(int height, int width):
player(10),
field(height, width)
{
    turn = std::make_unique<turns::StartMenuTurn>(*this);
    menu = Menu::GetStartMenu();
}

TimeLost::TimeLost(const TimeLost& time_lost):
player(time_lost.player),
field(time_lost.field)
{
    step_change = time_lost.step_change;
    items = time_lost.items;
    enemys = time_lost.enemys;
}

TimeLost& TimeLost::operator=(const TimeLost& time_lost)
{
    if(&time_lost == this) return *this;
    player = time_lost.player;
    field = time_lost.field;
    step_change = time_lost.step_change;
    items = time_lost.items;
    enemys = time_lost.enemys;
    return *this;
}

TimeLost::~TimeLost(){}

objects::Field& TimeLost::GetField(){
    return field;
}

objects::Player& TimeLost::GetPlayer(){
    return player;
}

void TimeLost::PlayerMove(types::Position move){
    types::Position new_pos = player.GetPosition() + move;
    if(new_pos.y >= field.GetHeight()) new_pos.y = field.GetHeight() - 1;
    if(new_pos.y < 0) new_pos.y = 0;
    if(new_pos.x >= field.GetWidth()) new_pos.x = field.GetWidth() - 1;
    if(new_pos.x < 0) new_pos.x = 0;
    if(field.GetCell(new_pos).GetType() != types::CellType::kBlock)
        player.SetPosition(new_pos);
    step_change--;
    if(step_change == 0){
        step_change = STEP_CHANGE;
        field.ChangeLayout();
        player.SetPosition(field.GetNewPosition(player.GetPosition()));
        for(auto item: items){
            item->SetPosition(field.GetNewPosition(item->GetPosition()));
        }
        for(auto enemy: enemys)
            enemy->SetPosition(field.GetNewPosition(enemy->GetPosition()));
    }
}

void TimeLost::PlayerChangeDirection(types::Direction direct){
    player.SetDirection(direct);
}

void TimeLost::PlayerInteract(){
    types::Position pos = player.GetPosition();
    for(auto item: items){
        if(item->GetPosition() == pos){
            player+=*item;
            item->SetOnField(false);
        }
    }
    items.remove_if([](std::shared_ptr<objects::Item> item){return !item->IsOnField();});
}

void TimeLost::PlayerAttack(){
    auto player_pos = player.GetPosition();
    auto player_direct = player.GetDirection();
    std::list<std::shared_ptr<objects::Enemy>> close_enemy;
    for(auto enemy: enemys){
        auto enemy_pos = enemy->GetPosition();
        if((player_direct == types::Direction::kDown || player_direct == types::Direction::kUp) &&
            enemy_pos.x == player_pos.x && abs(enemy_pos.y - player_pos.y) < 10) //FIXME: Replace 10 by LOCATION_SIZE
            close_enemy.push_back(enemy);
        else if((player_direct == types::Direction::kRight || player_direct == types::Direction::kLeft) &&
            enemy_pos.y == player_pos.y && abs(enemy_pos.x - player_pos.x) < 10)
            close_enemy.push_back(enemy);
    }
    int range, damage, dec_damage;

    std::tie (range, damage, dec_damage) = player.Attack();
    for(int i = 0; i < range; i++){
        if(damage <= 0) break;
        types::Position cur_pos;
        switch(player_direct){
            case types::Direction::kDown:
                cur_pos = player_pos + types::Position(0, i);
                break;
            case types::Direction::kUp:
                cur_pos = player_pos + types::Position(0, -i);
                break;
            case types::Direction::kRight:
                cur_pos = player_pos + types::Position(i, 0);
                break;
            case types::Direction::kLeft:
                cur_pos = player_pos + types::Position(-i, 0);
                break;
            default:
                throw types::TimeLostException(__FILE__, __LINE__, "Unknown Direction");
        }
        if(cur_pos.x < 0 || cur_pos.x >= field.GetWidth() || cur_pos.y < 0 || cur_pos.y >= field.GetHeight()) break;
        if(field.GetCell(cur_pos).GetType() == types::CellType::kBlock) break;
        for(auto enemy: close_enemy){
            if(enemy->GetPosition() == cur_pos){
                enemy->ChangeHealth(-damage);
                damage -= dec_damage;
                // FIXME: Without break??
                break;
            }
        }
    }
    // FIXME: Move to enemy actions and rework for the die animation
    enemys.remove_if([](std::shared_ptr<objects::Enemy> enemy){return enemy->GetHealth() <= 0;});
}

void TimeLost::PlayerChangeWeapon(types::WeaponType weapon){
    player.ChangeWeapon(weapon);
}

void TimeLost::PlayerReload(){
    player.Reload();
}

void TimeLost::AddItem(objects::Item& item){
    std::shared_ptr<objects::Item> _item = item.CloneItem();
    types::Position pos = _item->GetPosition();
    while(field.GetCell(pos).GetType() != types::CellType::kEmpty){
        pos.x++;
        if(pos.x == field.GetWidth()){
            pos.x = 0;
            pos.y++;
            if(pos.y == field.GetHeight()){
                pos.y = 0;
            }
        }
    }
    _item->SetPosition(pos);
    items.push_back(_item);
}

void TimeLost::AddItem(objects::Item&& item){
    std::shared_ptr<objects::Item> _item = item.CloneItem();
    types::Position pos = _item->GetPosition();
    while(field.GetCell(pos).GetType() != types::CellType::kEmpty){
        pos.x++;
        if(pos.x == field.GetWidth()){
            pos.x = 0;
            pos.y++;
            if(pos.y == field.GetHeight()){
                pos.y = 0;
            }
        }
    }
    _item->SetPosition(pos);
    items.push_back(_item);
}

std::list<std::shared_ptr<objects::Item>>::const_iterator TimeLost::GetItemIteratorBegin(){
    return items.cbegin();
}

std::list<std::shared_ptr<objects::Item>>::const_iterator TimeLost::GetItemIteratorEnd(){
    return items.cend();
}

std::list<std::shared_ptr<objects::Enemy>>::const_iterator TimeLost::GetEnemyIteratorBegin(){
    return enemys.cbegin();
}

std::list<std::shared_ptr<objects::Enemy>>::const_iterator TimeLost::GetEnemyIteratorEnd(){
    return enemys.cend();
}

void TimeLost::Start(){
    step_change = STEP_CHANGE;
    player = objects::Player(10);
    field.GenerateField();
    bool no_start = true;
    for(objects::FieldIterator it(field); !it(); it++){
        if((*it).GetType() == types::CellType::kEntry){
            no_start = false;
            player.SetPosition(it.GetCurrentPosition());
        }
    }
    if(no_start) throw types::TimeLostException("No start point on map\n");
    //FIXME: DELETE THIS
    if(field.GetHeight() <= 2*LOCATION_SIZE || field.GetWidth() <= 2*LOCATION_SIZE) return;
    AddItem(time_lost::objects::Bullets(4, types::BulletType::kRifle, {10,10}));
    AddItem(time_lost::objects::Bullets(6, types::BulletType::kRifle, {0,0}));
    AddItem(time_lost::objects::Bullets(10, types::BulletType::kRifle, {7,13}));
    AddItem(time_lost::objects::FirstAidKit(3,{3,6}));
    AddItem(time_lost::objects::FirstAidKit(7,{3,9}));
    AddItem(time_lost::objects::Bullets(1, types::BulletType::kPistol, {8,7}));
    AddItem(time_lost::objects::Bullets(11,types::BulletType::kPistol, {8,13}));
    AddItem(time_lost::objects::Bullets(111,types::BulletType::kPistol, {13,7}));
    types::Position pos = {rand() % field.GetWidth(), rand()% field.GetHeight()};
    while(field.GetCell(pos).GetType() == types::CellType::kBlock || abs(pos.x - player.GetPosition().x) <LOCATION_SIZE 
            || abs(pos.y - player.GetPosition().y) <LOCATION_SIZE){
        pos = {rand() % field.GetWidth(), rand()% field.GetHeight()};
    }
    enemys.emplace_back(std::make_shared<objects::EnemyType<types::BehaviorFind>>(13, pos));
    bool isEmpty = true;
    pos = {rand() % field.GetWidth(), rand()% field.GetHeight()};
    do{
        while(field.GetCell(pos).GetType() == types::CellType::kBlock || abs(pos.x - player.GetPosition().x) < LOCATION_SIZE 
            || abs(pos.y - player.GetPosition().y) < LOCATION_SIZE){
            pos = {rand() % field.GetWidth(), rand()% field.GetHeight()};
        }
        isEmpty = true;
        for(auto en: enemys)
            if(en->GetPosition() == pos) 
                isEmpty = false;
        if(!isEmpty) pos = {rand() % field.GetWidth(), rand()% field.GetHeight()};
    }while(!isEmpty);
    enemys.emplace_back(std::make_shared<objects::EnemyType<types::BehaviorWait>>(13, pos));
    pos = {rand() % field.GetWidth(), rand()% field.GetHeight()};
    isEmpty = true;
    do{
        while(field.GetCell(pos).GetType() == types::CellType::kBlock || abs(pos.x - player.GetPosition().x) < LOCATION_SIZE 
            || abs(pos.y - player.GetPosition().y) < LOCATION_SIZE){
            pos = {rand() % field.GetWidth(), rand()% field.GetHeight()};
        }
        isEmpty = true;
        for(auto en: enemys)
            if(en->GetPosition() == pos) 
                isEmpty = false;
        if(!isEmpty) pos = {rand() % field.GetWidth(), rand()% field.GetHeight()};
    }while(!isEmpty);
    enemys.emplace_back(std::make_shared<objects::EnemyType<types::BehaviorFly>>(13, pos));
}

void TimeLost::Win(){
    if(field.GetCell(player.GetPosition()).GetType() == types::CellType::kExit)
        SetTurn(std::make_unique<turns::WinTurn>(*this));
}

void TimeLost::Lose(){
    if (player.GetHealth() <= 0)
        SetTurn(std::make_unique<turns::LoseTurn>(*this));
}

void TimeLost::ExecuteCommand(Command& cmd){
    cmd.Execute(*this);
    if(!cmd.IsEmpty()) NextTurn();
    Lose();
    Win();
}

void TimeLost::ExecuteCommand(Command&& cmd){
    cmd.Execute(*this);
    if(!cmd.IsEmpty()) NextTurn();
    Lose();
    Win();
}

void TimeLost::EnemysAct(){
    for(auto enemy: enemys)
        enemy->DoSomething(field, player);
}

void TimeLost::SetTurn(std::unique_ptr<TurnInterface> new_turn){
    turn = std::move(new_turn);
}

void TimeLost::Pause(){
    turn->Pause();
}

void TimeLost::NextTurn(){
    turn->NextTurn();
}

bool TimeLost::IsPause(){
    return turn->GetTurn() == types::Turns::kPause;
}

types::Turns::Turn TimeLost::GetTurn(){
    return turn->GetTurn();
}

void TimeLost::Save(){
    SaveWriter sw("time_lost.save");
    sw.WriteSave(saves::TimeLostSave(player, field, items, enemys, step_change));
}

void TimeLost::Load(){
    SaveReader sr("time_lost.save");
    saves::TimeLostSave save = sr.ReadSave();
    *this = save.LoadTimeLost();
    //FIXME: Change States!
    turn = std::make_unique<turns::PauseTurn>(*this);
    srand(time(nullptr));
}

void TimeLost::MenuUp(){
    if(turn->GetTurn() == types::Turns::kStartMenu) menu.SelectUp();
}

void TimeLost::MenuDown(){
    if(turn->GetTurn() == types::Turns::kStartMenu) menu.SelectDown();
}

void TimeLost::MenuExecute(){
    if(turn->GetTurn() == types::Turns::kStartMenu) menu.Execute(*this);
}

const Menu& TimeLost::GetMenu(){
    return menu;
}

} // logic
} // time_lost