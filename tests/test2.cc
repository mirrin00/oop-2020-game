#include <boost/test/unit_test.hpp>

#include "etu_game/objects/sword.h"
#include "etu_game/objects/item.h"
#include "etu_game/objects/hands.h"
#include "etu_game/objects/health_potion.h"
#include "etu_game/objects/coin.h"

using namespace etu_game;
using namespace objects;

BOOST_AUTO_TEST_SUITE(test2) //("Testing Items: Item, Sword, Hands, HealthPotion and Coin","[test2]"){
    BOOST_AUTO_TEST_CASE(test_sword){ //("Sword and Hands"){
        Sword sw1(3,5,6);
        sw1.SetCanUse(true);
        BOOST_TEST_REQUIRE(sw1.GetHeightPosition() == 5);
        BOOST_TEST_REQUIRE(sw1.GetWidthPosition() == 6);
        BOOST_TEST_REQUIRE(sw1.Attack() == 3);
        Sword sw2 = sw1;
        BOOST_TEST_REQUIRE(sw2.GetHeightPosition() == 5);
        BOOST_TEST_REQUIRE(sw2.GetWidthPosition() == 6);
        BOOST_TEST_REQUIRE(sw2.Attack() == 3);
        sw2.SetWidthPosition(42);
        BOOST_TEST_REQUIRE(sw2.GetWidthPosition() == 42);
        Hands hands;
        std::unique_ptr<Weapon> weapon = Hands().clone();
        BOOST_TEST_REQUIRE(weapon->Attack() == 0);
        weapon = sw2.clone();
        BOOST_TEST_REQUIRE(weapon->Attack() == 3);
    }
    //TODO: tests for HP and Coin, before do copy operator to them
BOOST_AUTO_TEST_SUITE_END()