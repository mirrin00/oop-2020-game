#include <boost/test/unit_test.hpp>

#include "etu_game/objects/sword.h"
#include "etu_game/objects/item.h"
#include "etu_game/objects/hands.h"
#include "etu_game/objects/health_potion.h"
#include "etu_game/objects/coin.h"

using namespace etu_game;
using namespace objects;

BOOST_AUTO_TEST_SUITE(suite_2,  * boost::unit_test::label("test2"))
    BOOST_AUTO_TEST_CASE(test_1,
     * boost::unit_test::description("Testing Sword and Hands"))
    {
        Sword sw1(3,5,6);
        sw1.SetCanUse(true);
        BOOST_TEST_CHECK(sw1.GetHeightPosition() == 5);
        BOOST_TEST_CHECK(sw1.GetWidthPosition() == 6);
        BOOST_TEST_CHECK(sw1.Attack() == 3);
        BOOST_TEST_CHECK(sw1.IsCanUse() == true);
        BOOST_TEST_CHECK(sw1.IsOnField() == true);
        Sword sw2 = sw1;
        BOOST_TEST_CHECK(sw2.GetHeightPosition() == sw1.GetHeightPosition());
        BOOST_TEST_CHECK(sw2.GetWidthPosition() == sw1.GetWidthPosition());
        BOOST_TEST_CHECK(sw2.Attack() == sw1.Attack());
        BOOST_TEST_CHECK(sw2.IsCanUse() == sw1.IsCanUse());
        BOOST_TEST_CHECK(sw2.IsOnField() == sw1.IsOnField());
        sw2.SetWidthPosition(42);
        sw2.SetHeightPosition(-42);
        BOOST_TEST_CHECK(sw2.GetWidthPosition() == 42);
        BOOST_TEST_CHECK(sw2.GetHeightPosition() == -42);
        Sword sw3(10);
        BOOST_TEST_CHECK(sw3.IsCanUse() == false);
        sw3.SetCanUse(true);
        BOOST_TEST_CHECK(sw3.IsCanUse() == true);
        BOOST_TEST_CHECK(sw3.GetHeightPosition() == 0);
        BOOST_TEST_CHECK(sw3.GetWidthPosition() == 0);
        BOOST_TEST_CHECK(sw3.Attack() == 10);
        sw3 = sw1;
        BOOST_TEST_CHECK(sw3.GetHeightPosition() == sw1.GetHeightPosition());
        BOOST_TEST_CHECK(sw3.GetWidthPosition() == sw1.GetWidthPosition());
        BOOST_TEST_CHECK(sw3.Attack() == sw1.Attack());
        BOOST_TEST_CHECK(sw3.IsCanUse() == sw1.IsCanUse());
        BOOST_TEST_CHECK(sw3.IsOnField() == sw1.IsOnField());
        
        Hands hands;
        std::unique_ptr<Weapon> weapon = Hands().clone();
        BOOST_TEST_REQUIRE(weapon->Attack() == 0);
        weapon = sw2.clone();
        BOOST_TEST_REQUIRE(weapon->Attack() == 3);
    }
    BOOST_AUTO_TEST_CASE(test_2,
     * boost::unit_test::description("Testing Coin"))
    {
        Coin coin1(13,1,1);
        BOOST_TEST_CHECK(coin1.GetHeightPosition() == 1);
        BOOST_TEST_CHECK(coin1.GetWidthPosition() == 1);
        BOOST_TEST_CHECK(coin1.GetCount() == 13);
        BOOST_TEST_CHECK(coin1.IsCanUse() == false);
        BOOST_TEST_CHECK(coin1.IsOnField() == true);
        coin1.SetCanUse(true);
        BOOST_TEST_CHECK(coin1.IsCanUse() == true);
        coin1.SetOnField(false);
        BOOST_TEST_CHECK(coin1.IsOnField() == false);
        Coin coin2 = coin1;
        BOOST_TEST_CHECK(coin2.GetHeightPosition() == coin1.GetHeightPosition());
        BOOST_TEST_CHECK(coin2.GetWidthPosition() == coin1.GetWidthPosition());
        BOOST_TEST_CHECK(coin2.GetCount() == coin1.GetCount());
        BOOST_TEST_CHECK(coin2.IsCanUse() == coin1.IsCanUse());
        BOOST_TEST_CHECK(coin2.IsOnField() == coin1.IsOnField());
        coin2.SetWidthPosition(42);
        coin2.SetHeightPosition(-42);
        BOOST_TEST_CHECK(coin2.GetWidthPosition() == 42);
        BOOST_TEST_CHECK(coin2.GetHeightPosition() == -42);
        Coin coin3(3);
        BOOST_TEST_CHECK(coin3.GetHeightPosition() == 0);
        BOOST_TEST_CHECK(coin3.GetWidthPosition() == 0);
        BOOST_TEST_CHECK(coin3.GetCount() == 3);
        BOOST_TEST_CHECK(coin3.IsCanUse() == false);
        BOOST_TEST_CHECK(coin3.IsOnField() == true);
        coin3 = coin1;
        BOOST_TEST_CHECK(coin3.GetHeightPosition() == coin1.GetHeightPosition());
        BOOST_TEST_CHECK(coin3.GetWidthPosition() == coin1.GetWidthPosition());
        BOOST_TEST_CHECK(coin3.GetCount() == coin1.GetCount());
        BOOST_TEST_CHECK(coin3.IsCanUse() == coin1.IsCanUse());
        BOOST_TEST_CHECK(coin3.IsOnField() == coin1.IsOnField());
    }

    BOOST_AUTO_TEST_CASE(test_3,
     * boost::unit_test::description("Testing HealthPotion"))
    {
        HealthPotion health_poution1(13,1,1);
        BOOST_TEST_CHECK(health_poution1.GetHeightPosition() == 1);
        BOOST_TEST_CHECK(health_poution1.GetWidthPosition() == 1);
        BOOST_TEST_CHECK(health_poution1.GetHealthChange() == 13);
        BOOST_TEST_CHECK(health_poution1.IsCanUse() == false);
        BOOST_TEST_CHECK(health_poution1.IsOnField() == true);
        health_poution1.SetCanUse(true);
        BOOST_TEST_CHECK(health_poution1.IsCanUse() == true);
        health_poution1.SetOnField(false);
        BOOST_TEST_CHECK(health_poution1.IsOnField() == false);
        HealthPotion health_poution2 = health_poution1;
        BOOST_TEST_CHECK(health_poution2.GetHeightPosition() == health_poution1.GetHeightPosition());
        BOOST_TEST_CHECK(health_poution2.GetWidthPosition() == health_poution1.GetWidthPosition());
        BOOST_TEST_CHECK(health_poution2.GetHealthChange() == health_poution1.GetHealthChange());
        BOOST_TEST_CHECK(health_poution2.IsCanUse() == health_poution1.IsCanUse());
        BOOST_TEST_CHECK(health_poution2.IsOnField() == health_poution1.IsOnField());
        health_poution2.SetWidthPosition(42);
        health_poution2.SetHeightPosition(-42);
        BOOST_TEST_CHECK(health_poution2.GetWidthPosition() == 42);
        BOOST_TEST_CHECK(health_poution2.GetHeightPosition() == -42);
        HealthPotion health_poution3(3);
        BOOST_TEST_CHECK(health_poution3.GetHeightPosition() == 0);
        BOOST_TEST_CHECK(health_poution3.GetWidthPosition() == 0);
        BOOST_TEST_CHECK(health_poution3.GetHealthChange() == 3);
        BOOST_TEST_CHECK(health_poution3.IsCanUse() == false);
        BOOST_TEST_CHECK(health_poution3.IsOnField() == true);
        health_poution3 = health_poution1;
        BOOST_TEST_CHECK(health_poution3.GetHeightPosition() == health_poution1.GetHeightPosition());
        BOOST_TEST_CHECK(health_poution3.GetWidthPosition() == health_poution1.GetWidthPosition());
        BOOST_TEST_CHECK(health_poution3.GetHealthChange() == health_poution1.GetHealthChange());
        BOOST_TEST_CHECK(health_poution3.IsCanUse() == health_poution1.IsCanUse());
        BOOST_TEST_CHECK(health_poution3.IsOnField() == health_poution1.IsOnField());
    }
BOOST_AUTO_TEST_SUITE_END()