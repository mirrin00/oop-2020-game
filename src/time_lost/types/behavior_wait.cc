#include "time_lost/types/behavior_wait.h"

namespace time_lost{

namespace types{

void BehaviorWait::Do(objects::Enemy& enemy, objects::Field& field, objects::Player& player){
    Position player_pos = player.GetPosition(), enemy_pos = enemy.GetPosition();
    if(player_pos == enemy_pos){
        enemy += player;
        return;
    }
    if(abs(player_pos.y - enemy_pos.y) + abs(player_pos.x - enemy_pos.x) == 1){
        enemy += player;
        return;
    }
    if(abs(player_pos.x - enemy_pos.x) == 1 && abs(player_pos.y - enemy_pos.y) == 1){
        Position pos = player_pos + Position(1,0);
        if(pos.x < field.GetWidth() && abs(enemy_pos.y - pos.y) + abs(pos.x - enemy_pos.x) == 1 && field.GetCell(pos).GetType() != CellType::kBlock){
            enemy.SetPosition(pos);
            return;
        }
        pos = player_pos + Position(-1,0);
        if(pos.x >= 0 && abs(pos.y - enemy_pos.y) + abs(pos.x - enemy_pos.x) == 1 && field.GetCell(pos).GetType() != CellType::kBlock){
            enemy.SetPosition(pos);
            return;
        }
        pos = player_pos + Position(0,-1);
        if(pos.y >= 0 && abs(pos.y - enemy_pos.y) + abs(pos.x - enemy_pos.x) == 1 && field.GetCell(pos).GetType() != CellType::kBlock){
            enemy.SetPosition(pos);
            return;
        }
        pos = player_pos + Position(0,1);
        if(pos.y < field.GetHeight() && abs(pos.y - enemy_pos.y) + abs(pos.x - enemy_pos.x) == 1 && field.GetCell(pos).GetType() != CellType::kBlock){
            enemy.SetPosition(pos);
            return;
        }
    }
    if(abs(player_pos.x - enemy_pos.x) <= 2 && abs(player_pos.y - enemy_pos.y) <= 2){
        if(abs(player_pos.x - enemy_pos.x) != 2 || abs(player_pos.y - enemy_pos.y) != 2){
            if(abs(player_pos.x - enemy_pos.x) == 2){
                if(player_pos.x > enemy_pos.x && field.GetCell(enemy_pos + Position(1,0)).GetType() != CellType::kBlock){
                    enemy.Move({1,0});
                    return;
                }else if(field.GetCell(enemy_pos + Position(-1,0)).GetType() != CellType::kBlock){
                    enemy.Move({-1,0});
                    return;
                }
            }
            if(abs(player_pos.y - enemy_pos.y) == 2){
                if(player_pos.y > enemy_pos.y && field.GetCell(enemy_pos + Position(0,1)).GetType() != CellType::kBlock){
                    enemy.Move({0,1});
                    return;
                }else if(field.GetCell(enemy_pos + Position(0,-1)).GetType() != CellType::kBlock){
                    enemy.Move({0,-1});
                    return;
                }
            }
        }
    }
}

} // types
    
} // namespace time_lost
