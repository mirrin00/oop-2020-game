#include <boost/test/unit_test.hpp>

#include "time_lost/objects/sword.h"
#include "time_lost/objects/item.h"
#include "time_lost/objects/hands.h"
#include "time_lost/objects/first_aid_kit.h"
#include "time_lost/objects/bullets.h"

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
        BOOST_TEST_CHECK(sw1.GetPosition() == Position(6,5));
        BOOST_TEST_CHECK(sw1.Attack() == 3);
        BOOST_TEST_CHECK(sw1.IsOnField() == true);
        Sword sw2 = sw1;
        BOOST_TEST_CHECK(sw2.GetPosition() == sw1.GetPosition());
        BOOST_TEST_CHECK(sw2.Attack() == sw1.Attack());
        BOOST_TEST_CHECK(sw2.IsOnField() == sw1.IsOnField());
        sw2.SetPosition({42,-42});
        BOOST_TEST_CHECK(sw2.GetPosition() == Position(42,0));
        Sword sw3(10);
        BOOST_TEST_CHECK(sw3.GetPosition() == Position(0,0));
        BOOST_TEST_CHECK(sw3.Attack() == 10);
        sw3 = sw1;
        BOOST_TEST_CHECK(sw3.GetPosition() == sw1.GetPosition());
        BOOST_TEST_CHECK(sw3.Attack() == sw1.Attack());
        BOOST_TEST_CHECK(sw3.IsOnField() == sw1.IsOnField());
        
        Hands hands;
        std::unique_ptr<Weapon> weapon = Hands().CloneWeapon();
        BOOST_TEST_REQUIRE(weapon->Attack() == 0);
        weapon = sw2.CloneWeapon();
        BOOST_TEST_REQUIRE(weapon->Attack() == 3);
    }
    BOOST_AUTO_TEST_CASE(test_3,
     * boost::unit_test::description("Testing Bullets"))
    {
        Bullets bullets1(13, BulletType::kRifle, {1,1});
        BOOST_TEST_CHECK(bullets1.GetPosition() == Position(1,1));
        BOOST_TEST_CHECK(bullets1.GetCount() == 13);
        BOOST_TEST_CHECK(bullets1.GetType() == BulletType::kRifle);
        BOOST_TEST_CHECK(bullets1.IsOnField() == true);
        bullets1.SetOnField(false);
        BOOST_TEST_CHECK(bullets1.IsOnField() == false);
        Bullets bullets2 = bullets1;
        BOOST_TEST_CHECK(bullets2.GetPosition() == bullets2.GetPosition());
        BOOST_TEST_CHECK(bullets2.GetCount() == bullets1.GetCount());
        BOOST_TEST_CHECK(bullets2.GetType() == BulletType::kRifle);
        BOOST_TEST_CHECK(bullets2.IsOnField() == bullets1.IsOnField());
        bullets2.SetPosition({42,-42});
        BOOST_TEST_CHECK(bullets2.GetPosition() == Position(42,0));
        Bullets bullets3(3, BulletType::kPistol);
        BOOST_TEST_CHECK(bullets3.GetPosition() == Position(0,0));
        BOOST_TEST_CHECK(bullets3.GetCount() == 3);
        BOOST_TEST_CHECK(bullets3.GetType() == BulletType::kPistol);
        BOOST_TEST_CHECK(bullets3.IsOnField() == true);
        bullets3 = bullets1;
        BOOST_TEST_CHECK(bullets3.GetPosition() == bullets1.GetPosition());
        BOOST_TEST_CHECK(bullets3.GetCount() == bullets1.GetCount());
        BOOST_TEST_CHECK(bullets3.GetType() == BulletType::kRifle);
        BOOST_TEST_CHECK(bullets3.IsOnField() == bullets1.IsOnField());
    }

    BOOST_AUTO_TEST_CASE(test_4,
     * boost::unit_test::description("Testing FirstAidKit"))
    {
        FirstAidKit first_aid_kit1(13,{1,1});
        BOOST_TEST_CHECK(first_aid_kit1.GetPosition() == Position(1,1));
        BOOST_TEST_CHECK(first_aid_kit1.GetCount() == 13);
        BOOST_TEST_CHECK(first_aid_kit1.IsOnField() == true);
        first_aid_kit1.SetOnField(false);
        BOOST_TEST_CHECK(first_aid_kit1.IsOnField() == false);
        FirstAidKit first_aid_kit2 = first_aid_kit1;
        BOOST_TEST_CHECK(first_aid_kit2.GetPosition() == first_aid_kit1.GetPosition());
        BOOST_TEST_CHECK(first_aid_kit2.GetCount() == first_aid_kit1.GetCount());
        BOOST_TEST_CHECK(first_aid_kit2.IsOnField() == first_aid_kit1.IsOnField());
        first_aid_kit2.SetPosition({42,-42});
        BOOST_TEST_CHECK(first_aid_kit2.GetPosition() == Position(42,0));
        FirstAidKit first_aid_kit3(3);
        BOOST_TEST_CHECK(first_aid_kit3.GetPosition() == Position(0,0));
        BOOST_TEST_CHECK(first_aid_kit3.GetCount() == 3);
        first_aid_kit3.SetCount(78);
        BOOST_TEST_CHECK(first_aid_kit3.GetCount() == 78);
        BOOST_TEST_CHECK(first_aid_kit3.IsOnField() == true);
        first_aid_kit3 = first_aid_kit1;
        BOOST_TEST_CHECK(first_aid_kit3.GetPosition() == first_aid_kit1.GetPosition());
        BOOST_TEST_CHECK(first_aid_kit3.GetCount() == first_aid_kit1.GetCount());
        BOOST_TEST_CHECK(first_aid_kit3.IsOnField() == first_aid_kit1.IsOnField());
    }

BOOST_AUTO_TEST_SUITE_END()