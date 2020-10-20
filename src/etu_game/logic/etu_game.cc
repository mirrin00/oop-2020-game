#include "etu_game/logic/etu_game.h"

namespace etu_game{

namespace logic{

EtuGame::EtuGame(int height, int width):
player(10,0,0),
field(objects::Field::GetInstance(height, width))
{
}

EtuGame::~EtuGame(){}

objects::Field& EtuGame::GetField(){
    return field;
}

objects::Player& EtuGame::GetPlayer(){
    return player;
}

void EtuGame::PlayerMove(int h_pos, int w_pos){
    int h = player.GetHeightPosition() + h_pos;
    int w = player.GetWidthPosition() + w_pos;
    if(h < 0 || h >= field.GetHeight()) return;
    if(w < 0 || w >= field.GetWidth()) return;
    if(field.GetCell(h,w).GetType() != types::CellType::kBlock)
        player.Move(h_pos, w_pos);
}

void EtuGame::PlayerInteract(){
    int h_pos = player.GetHeightPosition();
    int w_pos = player.GetWidthPosition();
    for(int i = 0; i < items.size(); i++){
        if(items[i]->GetHeightPosition() == h_pos && items[i]->GetWidthPosition() == w_pos){
            player+=*(items[i]);
            items[i]->SetOnField(false);
        }
    }
}

void EtuGame::AddItem(objects::Item& item){
    items.push_back(item.clone());
}

void EtuGame::AddItem(objects::Item&& item){
    items.push_back(item.clone());
}

std::shared_ptr<objects::Item> EtuGame::GetItem(int index){
    if(index < 0 || index >= items.size()) return nullptr;
    return items[index];
}

void EtuGame::Start(){
    bool no_start = true;
    for(objects::FieldIterator it(field); !it(); it++){
        if((*it).GetType() == types::CellType::kEntry){
            no_start = false;
            player.SetHeightPosition(it.GetCurrentHeight());
            player.SetWidthPosition(it.GetCurrentWidth());
        }
    }
    if(no_start) throw types::EtuGameException(2,"No start point on map\n");
}

bool EtuGame::IsWin(){
    objects::Cell& cell = field.GetCell(player.GetHeightPosition(), player.GetWidthPosition());
    if(cell.GetType() == types::CellType::kExit) return true;
    return false;
}

} // logic
} // etu_game