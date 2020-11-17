#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

#include "time_lost/logic/time_lost.h"
#include "time_lost/logic/player_commands.h"

using namespace time_lost;
using namespace logic;
using namespace types;
using namespace objects;
using namespace commands;

BOOST_AUTO_TEST_SUITE(suite_5,  * boost::unit_test::label("test5"))


BOOST_AUTO_TEST_CASE(test_1,
     * boost::unit_test::description("Testing TimeLost and Commands"))
    {
        TimeLost game(1,1);
        game.Start();
        Player& player = game.GetPlayer();
        Field& field = game.GetField();
        BOOST_CHECK(field.GetCell(player.GetPosition()).GetType() == CellType::kEntry);
        bool exit = false;
        for(FieldIterator iter(field); !iter(); iter++){
            if((*iter).GetType() == CellType::kExit) exit = true;
            field.GetCell(iter.GetCurrentPosition()).SetType(CellType::kEmpty);
        }
        BOOST_CHECK(exit == true);
        int center = (LOCATION_SIZE-1)/2;
        player.SetPosition({center, center});
        game.ExecuteCommand(PlayerMoveUpCommand(game));
        BOOST_CHECK(player.GetPosition() == Position(center, center-1));
        game.ExecuteCommand(PlayerMoveLeftCommand(game));
        BOOST_CHECK(player.GetPosition() == Position(center-1, center-1));
        game.ExecuteCommand(PlayerMoveDownCommand(game));
        BOOST_CHECK(player.GetPosition() == Position(center-1, center));
        game.ExecuteCommand(PlayerMoveRightCommand(game));
        BOOST_CHECK(player.GetPosition() == Position(center, center));
        Position pos = {0,0};
        player.SetPosition(pos);
        field.GetCell({1,0}).SetType(CellType::kBlock);
        field.GetCell({0,1}).SetType(CellType::kBlock);
        game.ExecuteCommand(PlayerMoveLeftCommand(game));
        BOOST_CHECK(player.GetPosition() == pos);
        game.ExecuteCommand(PlayerMoveUpCommand(game));
        BOOST_CHECK(player.GetPosition() == pos);
        game.ExecuteCommand(PlayerMoveDownCommand(game));
        BOOST_CHECK(player.GetPosition() == pos);
        game.ExecuteCommand(PlayerMoveRightCommand(game));
        BOOST_CHECK(player.GetPosition() == pos);
        pos = {LOCATION_SIZE-1, LOCATION_SIZE-1};
        field.GetCell({pos.x,pos.y-1}).SetType(CellType::kBlock);
        field.GetCell({pos.x-1,pos.y}).SetType(CellType::kBlock);
        player.SetPosition(pos);
        game.ExecuteCommand(PlayerMoveRightCommand(game));
        BOOST_CHECK(player.GetPosition() == pos);
        game.ExecuteCommand(PlayerMoveDownCommand(game));
        BOOST_CHECK(player.GetPosition() == pos);
        game.ExecuteCommand(PlayerMoveLeftCommand(game));
        BOOST_CHECK(player.GetPosition() == pos);
        game.ExecuteCommand(PlayerMoveUpCommand(game));
        BOOST_CHECK(player.GetPosition() == pos);
        pos = {center,center};
        Coin coin(7, pos);
        coin.SetCanUse(true);
        game.AddItem(coin);
        player.SetPosition(pos);
        auto item = game.GetItem(0);
        BOOST_CHECK(item->GetPosition() == pos);
        BOOST_CHECK(item->IsOnField() == true);
        game.ExecuteCommand(PlayerInteractCommand(game));
        BOOST_CHECK(item->IsOnField() == false);
        BOOST_CHECK(player.GetCoins() == 7);
        BOOST_CHECK(game.IsWin() == false);
        field.GetCell(player.GetPosition()).SetType(CellType::kExit);
        BOOST_CHECK(game.IsWin() == true);
        field.GetCell(player.GetPosition()).SetType(CellType::kEmpty);
        BOOST_CHECK(game.IsWin() == false);
    }

BOOST_AUTO_TEST_SUITE_END()