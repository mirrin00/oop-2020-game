#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

#include "time_lost/logic/menu.h"
#include "time_lost/logic/player_commands.h"
#include "time_lost/logic/turns/enemy_turn.h"
#include "time_lost/logic/turns/pause_turn.h"
#include "time_lost/logic/turns/player_turn.h"
#include "time_lost/logic/turn_interface.h"
#include "time_lost/logic/menu_items/menu_item_exit.h"
#include "time_lost/types/time_lost_file_exception.h"

using namespace time_lost;
using namespace logic;
using namespace types;
using namespace objects;
using namespace turns;
using namespace menu_items;

BOOST_AUTO_TEST_SUITE(suite_6,  * boost::unit_test::label("test6"))

    BOOST_AUTO_TEST_CASE(test_1,
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
        BOOST_TEST_CHECK(player1.GetRifleBullets() == player2.GetRifleBullets());
        BOOST_TEST_CHECK(player1.GetPistolBullets() == player2.GetPistolBullets());
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
            BOOST_TEST_CHECK(player1.GetRifleBullets() == player2.GetRifleBullets());
            BOOST_TEST_CHECK(player1.GetPistolBullets() == player2.GetPistolBullets());
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

    BOOST_AUTO_TEST_CASE(test_2,
     * boost::unit_test::description("Testing Menu"))
    {
        Menu menu = Menu::GetStartMenu();
        for(int i=0; i<menu.GetItems().size(); i++){
            auto items = menu.GetItems();
            for(int j=0; j<items.size(); j++){
                BOOST_TEST_CHECK( (items[j]->IsSelected() == true) == (i == j) );
            }
            menu.SelectDown();
        }
        BOOST_TEST_CHECK(menu.GetItems()[0]->IsSelected() == true);
        menu.SelectUp();
        BOOST_TEST_CHECK(menu.GetItems()[menu.GetItems().size()-1]->IsSelected() == true);
        int i = menu.GetItems().size() - 1;
        while(!dynamic_cast<MenuItemExit*>(menu.GetItems()[i].get())){
            menu.SelectUp();
            i--;
            if(i < 0) BOOST_TEST_FAIL("In Menu no Exit");
        }
        TimeLost game(1,1);
        menu.Execute(game);
        BOOST_TEST_CHECK(game.GetTurn() == Turns::kExit);
    }

BOOST_AUTO_TEST_SUITE_END()

