#include "time_lost/types/behavior_fly.h"

namespace time_lost{

namespace types{

void BehaviorFly::Do(objects::Enemy& enemy, objects::Field& field, objects::Player& player){
    Position player_pos = player.GetPosition(), enemy_pos = enemy.GetPosition();
    if(player_pos == enemy_pos){
        enemy += player;
        return;
    }
    if(abs(player_pos.x - enemy_pos.x) + abs(player_pos.y - enemy_pos.y) <= 2){
        enemy.SetPosition(player_pos);
        enemy += player;
        return;
    }
    int dx = player_pos.x - enemy_pos.x, dy = player_pos.y - enemy_pos.y;
    if(abs(dx) > abs(dy)){
        if(dx > 0 && field.GetCell(enemy_pos + Position(2,0)).GetType() != CellType::kBlock){
            enemy.Move({2,0});
            return;
        }
        if(dx > 0 && field.GetCell(enemy_pos + Position(1,0)).GetType() != CellType::kBlock){
            enemy.Move({1,0});
            return;
        }
        if(dx < 0 && field.GetCell(enemy_pos + Position(-2,0)).GetType() != CellType::kBlock){
            enemy.Move({-2,0});
            return;
        }
        if(dx < 0 && field.GetCell(enemy_pos + Position(-1,0)).GetType() != CellType::kBlock){
            enemy.Move({-1,0});
            return;
        }
    }else{
        if(dy > 0 && field.GetCell(enemy_pos + Position(0,2)).GetType() != CellType::kBlock){
            enemy.Move({0,2});
            return;
        }
        if(dy > 0 && field.GetCell(enemy_pos + Position(0,1)).GetType() != CellType::kBlock){
            enemy.Move({0,1});
            return;
        }
        if(dy < 0 && field.GetCell(enemy_pos + Position(0,-2)).GetType() != CellType::kBlock){
            enemy.Move({0,-2});
            return;
        }
        if(dy < 0 && field.GetCell(enemy_pos + Position(0,-1)).GetType() != CellType::kBlock){
            enemy.Move({0,-1});
            return;
        }
    }
    Position pos = enemy_pos + Position(2,0);
    if(pos.x < field.GetWidth() && field.GetCell(pos).GetType() != CellType::kBlock){
        enemy.Move({2,0});
        return;
    }
    pos = enemy_pos + Position(1,0);
    if(pos.x < field.GetWidth() && field.GetCell(pos).GetType() != CellType::kBlock){
        enemy.Move({1,0});
        return;
    }
    pos = enemy_pos + Position(0,2);
    if(pos.y < field.GetHeight() && field.GetCell(pos).GetType() != CellType::kBlock){
        enemy.Move({0,2});
        return;
    }
    pos = enemy_pos + Position(0,1);
    if(pos.y < field.GetHeight() && field.GetCell(pos).GetType() != CellType::kBlock){
        enemy.Move({0,1});
        return;
    }
    pos = enemy_pos + Position(-2,0);
    if(pos.x >= 0 && field.GetCell(pos).GetType() != CellType::kBlock){
        enemy.Move({-2,0});
        return;
    }
    pos = enemy_pos + Position(-1,0);
    if(pos.x >= 0 && field.GetCell(pos).GetType() != CellType::kBlock){
        enemy.Move({-1,0});
        return;
    }
    pos = enemy_pos + Position(0,-2);
    if(pos.y >= 0 && field.GetCell(pos).GetType() != CellType::kBlock){
        enemy.Move({0,-2});
        return;
    }
    pos = enemy_pos + Position(0,-1);
    if(pos.y >= 0 && field.GetCell(pos).GetType() != CellType::kBlock){
        enemy.Move({0,-1});
        return;
    }
}

void BehaviorFly::Attack(objects::Player& player){
    player.ChangeHealth(-2);
}

SaveType::Type BehaviorFly::GetSaveType(){
    return SaveType::kEnemyFly;
}


} // types
    
} // namespace time_lost