#include <boost/test/unit_test.hpp>

#include "time_lost/objects/sword.h"
#include "time_lost/objects/item.h"
#include "time_lost/objects/hands.h"
#include "time_lost/objects/health_potion.h"
#include "time_lost/objects/coin.h"

using namespace time_lost;
using namespace objects;
using namespace types;

BOOST_AUTO_TEST_SUITE(suite_2,  * boost::unit_test::label("test2"))
    BOOST_AUTO_TEST_CASE(test_1,
     * boost::unit_test::description("Testing Position"))
    {
        Position pos;
        BOOST_TEST_CHECK(pos.x == 0);
        BOOST_TEST_CHECK(pos.y == 0);
        pos = {1,4};
        BOOST_TEST_CHECK(pos.x == 1);
        BOOST_TEST_CHECK(pos.y == 4);
        Position pos2 = {10,5};
        BOOST_TEST_CHECK(pos2.x == 10);
        BOOST_TEST_CHECK(pos2.y == 5);
        Position pos3 = pos + pos2;
        BOOST_TEST_CHECK(pos3.x == 11);
        BOOST_TEST_CHECK(pos3.y == 9);
        pos3 = pos - pos2;
        BOOST_TEST_CHECK(pos3.x == -9);
        BOOST_TEST_CHECK(pos3.y == -1);
        pos3 = -pos2;
        BOOST_TEST_CHECK(pos3.x == -10);
        BOOST_TEST_CHECK(pos3.y == -5);
        BOOST_TEST_CHECK(pos3.SumAbs() == 15);
    }

    BOOST_AUTO_TEST_CASE(test_2,
     * boost::unit_test::description("Testing Sword and Hands"))
    {
        Sword sw1(3,{6,5});
        sw1.SetCanUse(true);
        BOOST_TEST_CHECK(sw1.GetPosition() == Position(6,5));
        BOOST_TEST_CHECK(sw1.Attack() == 3);
        BOOST_TEST_CHECK(sw1.IsCanUse() == true);
        BOOST_TEST_CHECK(sw1.IsOnField() == true);
        Sword sw2 = sw1;
        BOOST_TEST_CHECK(sw2.GetPosition() == sw1.GetPosition());
        BOOST_TEST_CHECK(sw2.Attack() == sw1.Attack());
        BOOST_TEST_CHECK(sw2.IsCanUse() == sw1.IsCanUse());
        BOOST_TEST_CHECK(sw2.IsOnField() == sw1.IsOnField());
        sw2.SetPosition({42,-42});
        BOOST_TEST_CHECK(sw2.GetPosition() == Position(42,0));
        Sword sw3(10);
        BOOST_TEST_CHECK(sw3.IsCanUse() == false);
        sw3.SetCanUse(true);
        BOOST_TEST_CHECK(sw3.IsCanUse() == true);
        BOOST_TEST_CHECK(sw3.GetPosition() == Position(0,0));
        BOOST_TEST_CHECK(sw3.Attack() == 10);
        sw3 = sw1;
        BOOST_TEST_CHECK(sw3.GetPosition() == sw1.GetPosition());
        BOOST_TEST_CHECK(sw3.Attack() == sw1.Attack());
        BOOST_TEST_CHECK(sw3.IsCanUse() == sw1.IsCanUse());
        BOOST_TEST_CHECK(sw3.IsOnField() == sw1.IsOnField());
        
        Hands hands;
        std::unique_ptr<Weapon> weapon = Hands().CloneWeapon();
        BOOST_TEST_REQUIRE(weapon->Attack() == 0);
        weapon = sw2.CloneWeapon();
        BOOST_TEST_REQUIRE(weapon->Attack() == 3);
    }
    BOOST_AUTO_TEST_CASE(test_3,
     * boost::unit_test::description("Testing Coin"))
    {
        Coin coin1(13,{1,1});
        BOOST_TEST_CHECK(coin1.GetPosition() == Position(1,1));
        BOOST_TEST_CHECK(coin1.GetCount() == 13);
        BOOST_TEST_CHECK(coin1.IsCanUse() == false);
        BOOST_TEST_CHECK(coin1.IsOnField() == true);
        coin1.SetCanUse(true);
        BOOST_TEST_CHECK(coin1.IsCanUse() == true);
        coin1.SetOnField(false);
        BOOST_TEST_CHECK(coin1.IsOnField() == false);
        Coin coin2 = coin1;
        BOOST_TEST_CHECK(coin2.GetPosition() == coin2.GetPosition());
        BOOST_TEST_CHECK(coin2.GetCount() == coin1.GetCount());
        BOOST_TEST_CHECK(coin2.IsCanUse() == coin1.IsCanUse());
        BOOST_TEST_CHECK(coin2.IsOnField() == coin1.IsOnField());
        coin2.SetPosition({42,-42});
        BOOST_TEST_CHECK(coin2.GetPosition() == Position(42,0));
        Coin coin3(3);
        BOOST_TEST_CHECK(coin3.GetPosition() == Position(0,0));
        BOOST_TEST_CHECK(coin3.GetCount() == 3);
        BOOST_TEST_CHECK(coin3.IsCanUse() == false);
        BOOST_TEST_CHECK(coin3.IsOnField() == true);
        coin3 = coin1;
        BOOST_TEST_CHECK(coin3.GetPosition() == coin1.GetPosition());
        BOOST_TEST_CHECK(coin3.GetCount() == coin1.GetCount());
        BOOST_TEST_CHECK(coin3.IsCanUse() == coin1.IsCanUse());
        BOOST_TEST_CHECK(coin3.IsOnField() == coin1.IsOnField());
    }

    BOOST_AUTO_TEST_CASE(test_4,
     * boost::unit_test::description("Testing HealthPotion"))
    {
        HealthPotion health_poution1(13,{1,1});
        BOOST_TEST_CHECK(health_poution1.GetPosition() == Position(1,1));
        BOOST_TEST_CHECK(health_poution1.GetHealthChange() == 13);
        BOOST_TEST_CHECK(health_poution1.IsCanUse() == false);
        BOOST_TEST_CHECK(health_poution1.IsOnField() == true);
        health_poution1.SetCanUse(true);
        BOOST_TEST_CHECK(health_poution1.IsCanUse() == true);
        health_poution1.SetOnField(false);
        BOOST_TEST_CHECK(health_poution1.IsOnField() == false);
        HealthPotion health_poution2 = health_poution1;
        BOOST_TEST_CHECK(health_poution2.GetPosition() == health_poution1.GetPosition());
        BOOST_TEST_CHECK(health_poution2.GetHealthChange() == health_poution1.GetHealthChange());
        BOOST_TEST_CHECK(health_poution2.IsCanUse() == health_poution1.IsCanUse());
        BOOST_TEST_CHECK(health_poution2.IsOnField() == health_poution1.IsOnField());
        health_poution2.SetPosition({42,-42});
        BOOST_TEST_CHECK(health_poution2.GetPosition() == Position(42,0));
        HealthPotion health_poution3(3);
        BOOST_TEST_CHECK(health_poution3.GetPosition() == Position(0,0));
        BOOST_TEST_CHECK(health_poution3.GetHealthChange() == 3);
        BOOST_TEST_CHECK(health_poution3.IsCanUse() == false);
        BOOST_TEST_CHECK(health_poution3.IsOnField() == true);
        health_poution3 = health_poution1;
        BOOST_TEST_CHECK(health_poution3.GetPosition() == health_poution1.GetPosition());
        BOOST_TEST_CHECK(health_poution3.GetHealthChange() == health_poution1.GetHealthChange());
        BOOST_TEST_CHECK(health_poution3.IsCanUse() == health_poution1.IsCanUse());
        BOOST_TEST_CHECK(health_poution3.IsOnField() == health_poution1.IsOnField());
    }

BOOST_AUTO_TEST_SUITE_END()