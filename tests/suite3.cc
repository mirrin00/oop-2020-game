#include <boost/test/unit_test.hpp>

#include "etu_game/objects/sword.h"
#include "etu_game/objects/item.h"
#include "etu_game/objects/hands.h"
#include "etu_game/objects/health_potion.h"
#include "etu_game/objects/coin.h"
#include "etu_game/objects/player.h"

using namespace etu_game;
using namespace objects;

BOOST_AUTO_TEST_SUITE(suite_3,  * boost::unit_test::label("test3"))
    int h_pos = 43, w_pos = 41, health = 100;
    Player player(health, h_pos, w_pos);
    BOOST_AUTO_TEST_CASE(test_1,
     * boost::unit_test::description("Testing Essence moving by Player"))
    {
        BOOST_TEST_CHECK(player.GetHealth() == health);
        BOOST_TEST_CHECK(player.GetHeightPosition() == h_pos);
        BOOST_TEST_CHECK(player.GetWidthPosition() == w_pos);
        player.Move(15,-98);
        BOOST_TEST_CHECK(player.GetHeightPosition() == h_pos + 15);
        BOOST_TEST_CHECK(player.GetWidthPosition() == w_pos - 98);
        player.SetWidhtPosition(0);
        BOOST_TEST_CHECK(player.GetWidthPosition() == 0);
        player.SetHeightPosition(0);
        BOOST_TEST_CHECK(player.GetHeightPosition() == 0);
    }
    BOOST_AUTO_TEST_CASE(test_2,
     * boost::unit_test::description("Testing interacte Items with Player"))
    {
        BOOST_TEST_CHECK(player.GetCoins() == 0);
        Coin coin(25);
        coin.SetCanUse(true);
        player += coin;
        BOOST_TEST_CHECK(player.GetCoins() == 25);
        BOOST_TEST_CHECK(coin.IsCanUse() == false);
        HealthPotion potion(-58);
        potion.SetCanUse(true);
        player += potion;
        BOOST_TEST_CHECK(player.GetHealth() == 42);
        BOOST_TEST_CHECK(potion.IsCanUse() == false);
        potion = HealthPotion(1);
        potion.SetCanUse(true);
        player += potion;
        BOOST_TEST_CHECK(player.GetHealth() == 43);
        BOOST_TEST_CHECK(player.Attack() == 0);
        Sword sw1(10);
        sw1.SetCanUse(true);
        player += sw1;
        BOOST_TEST_CHECK(player.Attack() == 10);
    }
BOOST_AUTO_TEST_SUITE_END()