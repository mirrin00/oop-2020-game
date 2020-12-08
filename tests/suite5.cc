#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

#include "time_lost/logic/time_lost.h"
#include "time_lost/logic/player_commands.h"
#include "time_lost/logic/turns/enemy_turn.h"
#include "time_lost/logic/turns/pause_turn.h"
#include "time_lost/logic/turns/player_turn.h"
#include "time_lost/logic/turn_interface.h"
#include "time_lost/objects/enemy.h"
#include "time_lost/types/behavior_find.h"
#include "time_lost/types/behavior_wait.h"
#include "time_lost/types/behavior_fly.h"
#include "time_lost/types/time_lost_file_exception.h"

using namespace time_lost;
using namespace logic;
using namespace types;
using namespace objects;
using namespace commands;
using namespace turns;

BOOST_AUTO_TEST_SUITE(suite_5,  * boost::unit_test::label("test5"))


BOOST_AUTO_TEST_CASE(test_1,
     * boost::unit_test::description("Testing TimeLost and Commands"))
    {
        TimeLost game(1,1);
        BOOST_TEST_CHECKPOINT("Check1");
        game.Start();
        Player& player = game.GetPlayer();
        Field& field = game.GetField();
        BOOST_TEST_CHECK(field.GetCell(player.GetPosition()).GetType() == CellType::kEntry);
        bool exit = false;
        for(FieldIterator iter(field); !iter(); iter++){
            if((*iter).GetType() == CellType::kExit) exit = true;
            field.GetCell(iter.GetCurrentPosition()).SetType(CellType::kEmpty);
        }
        BOOST_TEST_CHECK(exit == true);
        game.SetTurn(std::make_unique<PlayerTurn>(game));
        int center = (LOCATION_SIZE-1)/2;
        player.SetPosition({center, center});
        game.ExecuteCommand(PlayerMoveUpCommand());
        game.ExecuteCommand(EmptyCommand());
        BOOST_TEST_CHECK(player.GetPosition() == Position(center, center-1));
        game.ExecuteCommand(PlayerMoveLeftCommand());
        game.ExecuteCommand(EmptyCommand());
        BOOST_TEST_CHECK(player.GetPosition() == Position(center-1, center-1));
        game.ExecuteCommand(PlayerMoveDownCommand());
        game.ExecuteCommand(EmptyCommand());
        BOOST_TEST_CHECK(player.GetPosition() == Position(center-1, center));
        game.ExecuteCommand(PlayerMoveRightCommand());
        game.ExecuteCommand(EmptyCommand());
        BOOST_TEST_CHECK(player.GetPosition() == Position(center, center));
        Position pos = {0,0};
        player.SetPosition(pos);
        field.GetCell({1,0}).SetType(CellType::kBlock);
        field.GetCell({0,1}).SetType(CellType::kBlock);
        game.ExecuteCommand(PlayerMoveLeftCommand());
        game.ExecuteCommand(EmptyCommand());
        BOOST_TEST_CHECK(player.GetPosition() == pos);
        game.ExecuteCommand(PlayerMoveUpCommand());
        game.ExecuteCommand(EmptyCommand());
        BOOST_TEST_CHECK(player.GetPosition() == pos);
        game.ExecuteCommand(PlayerMoveDownCommand());
        game.ExecuteCommand(EmptyCommand());
        BOOST_TEST_CHECK(player.GetPosition() == pos);
        game.ExecuteCommand(PlayerMoveRightCommand());
        game.ExecuteCommand(EmptyCommand());
        BOOST_TEST_CHECK(player.GetPosition() == pos);
        pos = {LOCATION_SIZE-1, LOCATION_SIZE-1};
        field.GetCell({pos.x,pos.y-1}).SetType(CellType::kBlock);
        field.GetCell({pos.x-1,pos.y}).SetType(CellType::kBlock);
        player.SetPosition(pos);
        game.ExecuteCommand(PlayerMoveRightCommand());
        game.ExecuteCommand(EmptyCommand());
        BOOST_TEST_CHECK(player.GetPosition() == pos);
        game.ExecuteCommand(PlayerMoveDownCommand());
        game.ExecuteCommand(EmptyCommand());
        BOOST_TEST_CHECK(player.GetPosition() == pos);
        game.ExecuteCommand(PlayerMoveLeftCommand());
        game.ExecuteCommand(EmptyCommand());
        BOOST_TEST_CHECK(player.GetPosition() == pos);
        game.ExecuteCommand(PlayerMoveUpCommand());
        game.ExecuteCommand(EmptyCommand());
        BOOST_TEST_CHECK(player.GetPosition() == pos);
        pos = {center,center};
        Coin coin(7, pos);
        coin.SetCanUse(true);
        game.AddItem(coin);
        player.SetPosition(pos);
        auto item = game.GetItem(0);
        BOOST_TEST_CHECK(item->GetPosition() == pos);
        BOOST_TEST_CHECK(item->IsOnField() == true);
        game.ExecuteCommand(PlayerInteractCommand());
        game.ExecuteCommand(EmptyCommand());
        BOOST_TEST_CHECK(item->IsOnField() == false);
        BOOST_TEST_CHECK(player.GetCoins() == 7);
        BOOST_TEST_CHECK(game.GetTurn() != Turns::kWin);
        field.GetCell(player.GetPosition()).SetType(CellType::kExit);
        game.ExecuteCommand(EmptyCommand());
        BOOST_TEST_CHECK(game.GetTurn() == Turns::kWin);
        //field.GetCell(player.GetPosition()).SetType(CellType::kEmpty);
        //BOOST_TEST_CHECK(game.IsWin() == false);
    }

    BOOST_AUTO_TEST_CASE(test_2,
     * boost::unit_test::description("Testing Turns"))
    {
        TimeLost game(1,1);
        std::unique_ptr<TurnInterface> turn = std::make_unique<PlayerTurn>(game);
        BOOST_TEST_CHECK(turn->GetTurn() == Turns::kPlayer);
        turn = std::make_unique<EnemyTurn>(game);
        BOOST_TEST_CHECK(turn->GetTurn() == Turns::kEnemy);
        turn = std::make_unique<PauseTurn>(game);
        BOOST_TEST_CHECK(turn->GetTurn() == Turns::kPause);
        game.Start();
        Player& player = game.GetPlayer();
        Field& field = game.GetField();
        BOOST_TEST_CHECK(field.GetCell(player.GetPosition()).GetType() == CellType::kEntry);
        bool exit = false;
        for(FieldIterator iter(field); !iter(); iter++){
            if((*iter).GetType() == CellType::kExit) exit = true;
            field.GetCell(iter.GetCurrentPosition()).SetType(CellType::kEmpty);
        }
        BOOST_TEST_CHECK(exit == true);
        game.SetTurn(std::make_unique<PlayerTurn>(game));
        BOOST_TEST_CHECK(game.IsPause() == false);
        game.Pause();
        BOOST_TEST_CHECK(game.IsPause() == true);
        game.Pause();
        BOOST_TEST_CHECK(game.IsPause() == false);
        game.NextTurn();
        int center = (LOCATION_SIZE-1)/2;
        Position pos = {center,center};
        player.SetPosition({center,center});
        game.ExecuteCommand(PlayerMoveLeftCommand());
        BOOST_TEST_CHECK(player.GetPosition() == pos);
        game.Pause();
        game.ExecuteCommand(PlayerMoveLeftCommand());
        BOOST_TEST_CHECK(player.GetPosition() == pos);
    }

    BOOST_AUTO_TEST_CASE(test_3,
     * boost::unit_test::description("Testing Enemy"))
    {
        Field field(1,1);
        field.GenerateField();
        for(FieldIterator iter(field); !iter(); iter++){
            field.GetCell(iter.GetCurrentPosition()).SetType(CellType::kEmpty);
        }
        int center = (LOCATION_SIZE-1)/2;
        Position pos = {center,center};
        Player player(10,pos);
        Sword sword(1);
        sword.SetCanUse(true);
        player += sword;
        std::unique_ptr<Enemy> enemy = std::make_unique<EnemyType<BehaviorFind>>(10);
        *enemy += player;
        BOOST_TEST_CHECK(player.GetHealth() == 9);
        player += *enemy;
        BOOST_TEST_CHECK(enemy->GetHealth() == 9);
        *enemy -= player;
        BOOST_TEST_CHECK(enemy->GetHealth() == 8);
        player -= *enemy;
        BOOST_TEST_CHECK(player.GetHealth() == 8);
        // Testing BehaviorFind
        // Testing {0,2}
        enemy = std::make_unique<EnemyType<BehaviorFind>>(10,pos - Position(2,0));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 1);
        enemy->SetPosition(pos - Position(-2,0));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 1);
        enemy->SetPosition(pos - Position(0,2));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 1);
        enemy->SetPosition(pos - Position(0,-2));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 1);
        // Testint {1,1}
        enemy->SetPosition(pos - Position(1,1));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 1);
        enemy->SetPosition(pos - Position(1,-1));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 1);
        enemy->SetPosition(pos - Position(-1,1));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 1);
        enemy->SetPosition(pos - Position(-1,-1));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 1);
        player.SetPosition({100,100});
        enemy->SetPosition(pos);
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK(enemy->GetPosition() != pos);
        // Testing BehaviorWait
        // Testing {0,2}
        player.SetPosition(pos);
        enemy = std::make_unique<EnemyType<BehaviorWait>>(10,pos - Position(2,0));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 1);
        enemy->SetPosition(pos - Position(-2,0));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 1);
        enemy->SetPosition(pos - Position(0,2));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 1);
        enemy->SetPosition(pos - Position(0,-2));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 1);
        // Testint {1,1}
        enemy->SetPosition(pos - Position(1,1));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 1);
        enemy->SetPosition(pos - Position(1,-1));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 1);
        enemy->SetPosition(pos - Position(-1,1));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 1);
        enemy->SetPosition(pos - Position(-1,-1));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 1);
        player.SetPosition({100,100});
        enemy->SetPosition(pos);
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK(enemy->GetPosition() == pos);
        // Testing BehaviorFly
        // Testing {0,2}
        pos = {0,0};
        player.SetPosition(pos);
        enemy = std::make_unique<EnemyType<BehaviorFly>>(10,pos + Position(2,0));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 0);
        enemy->SetPosition(pos + Position(0,2));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 0);
        // Testint {4,0}
        enemy->SetPosition(pos + Position(4,0));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 2);
        enemy->SetPosition(pos + Position(0,4));
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK((enemy->GetPosition() - pos).SumAbs() == 2);
        player.SetPosition({100,100});
        enemy->SetPosition(pos);
        enemy->DoSomething(field, player);
        BOOST_TEST_CHECK(enemy->GetPosition() != pos);
        //TODO: Enemy don't walk into walls
    }

    BOOST_AUTO_TEST_CASE(test_4,
     * boost::unit_test::description("Testing Save, Load and TimeLostFileException"))
    {
        TimeLost game(4,4);
        BOOST_CHECK_THROW(game.Load(), TimeLostFileException);
        game.Start();
        game.SetTurn(std::make_unique<PlayerTurn>(game));
        game.Save();
        TimeLost game2(1,1);
        game2.Load();
        Field& field1 = game.GetField();
        Field& field2 = game2.GetField();
        for(FieldIterator iter(field2); !iter(); iter++){
            BOOST_TEST_CHECK((*iter).GetType() == field1.GetCell(iter.GetCurrentPosition()).GetType());
        }
        Player& player1 = game.GetPlayer();
        Player& player2 = game2.GetPlayer();
        BOOST_TEST_CHECK(player1.GetCoins() == player2.GetCoins());
        BOOST_TEST_CHECK(player1.GetHealth() == player2.GetHealth());
        BOOST_TEST_CHECK(player1.GetPosition() == player2.GetPosition());
        BOOST_TEST_CHECK(player1.Attack() == player2.Attack());
        int i = 0;
        std::shared_ptr<Item> item1 = game.GetItem(i);
        std::shared_ptr<Item> item2 = game2.GetItem(i);
        while(item1 && item2){
            BOOST_TEST_CHECK(item1->GetPosition() == item2->GetPosition());
            player1 += *(item1->CloneItem());
            player2 += *(item2->CloneItem());
            BOOST_TEST_CHECK(player1.GetCoins() == player2.GetCoins());
            BOOST_TEST_CHECK(player1.GetHealth() == player2.GetHealth());
            BOOST_TEST_CHECK(player1.Attack() == player2.Attack());
            i++;
            item1 = game.GetItem(i);
            item2 = game2.GetItem(i);
        }
        BOOST_TEST_CHECK((item1 == nullptr) == (item2 == nullptr));
        i = 0;
        std::shared_ptr<Enemy> enemy1 = game.GetEnemy(i);
        std::shared_ptr<Enemy> enemy2 = game2.GetEnemy(i);
        while(enemy1 && enemy2){
            BOOST_TEST_CHECK(enemy1->GetPosition() == enemy2->GetPosition());
            BOOST_TEST_CHECK(enemy1->GetHealth() == enemy2->GetHealth());
            i++;
            enemy1 = game.GetEnemy(i);
            enemy2 = game2.GetEnemy(i);
        }
        BOOST_TEST_CHECK((enemy1 == nullptr) == (enemy2 == nullptr));
        std::fstream file("time_lost.save", std::fstream::out);
        for(int i=0; i<5;i++) file << 0x123456;
        file.close();
        BOOST_CHECK_THROW(game.Load(), TimeLostException);
    }

BOOST_AUTO_TEST_SUITE_END()