#include <boost/test/unit_test.hpp>

#include "time_lost/objects/sword.h"
#include "time_lost/objects/item.h"
#include "time_lost/objects/hands.h"
#include "time_lost/objects/first_aid_kit.h"
#include "time_lost/objects/bullets.h"
#include "time_lost/objects/player.h"

using namespace time_lost;
using namespace objects;
using namespace types;

BOOST_AUTO_TEST_SUITE(suite_3,  * boost::unit_test::label("test3"))
    int h_pos = 43, w_pos = 41, health = 100;
    Player player(health, {h_pos, w_pos});
    BOOST_AUTO_TEST_CASE(test_1,
     * boost::unit_test::description("Testing Essence moving and direction by Player"))
    {
        BOOST_TEST_CHECK(player.GetHealth() == health);
        BOOST_TEST_CHECK(player.GetPosition() == Position(h_pos, w_pos));
        player.Move({15,-98});
        Position pos = {h_pos + 15, w_pos - 98};
        if(pos.x < 0) pos.x = 0;
        if(pos.y < 0) pos.y = 0;
        BOOST_TEST_CHECK(player.GetPosition() == pos);
        player.SetPosition({0,0});
        BOOST_TEST_CHECK(player.GetPosition() == Position(0,0));
        BOOST_TEST_CHECK(player.GetDirection() == types::Direction::kUp);
        player.SetDirection(types::Direction::kDown);
        BOOST_TEST_CHECK(player.GetDirection() == types::Direction::kDown);
        player.SetDirection(types::Direction::kLeft);
        BOOST_TEST_CHECK(player.GetDirection() == types::Direction::kLeft);
        player.SetDirection(types::Direction::kRight);
        BOOST_TEST_CHECK(player.GetDirection() == types::Direction::kRight);
        player.SetDirection(types::Direction::kUp);
        BOOST_TEST_CHECK(player.GetDirection() == types::Direction::kUp);
    }
    BOOST_AUTO_TEST_CASE(test_2,
     * boost::unit_test::description("Testing interacte Items with Player"))
    {
        BOOST_TEST_CHECK(player.GetRifleBullets() == 0);
        BOOST_TEST_CHECK(player.GetPistolBullets() == 0);
        Bullets p_bul(10, BulletType::kPistol);
        player += p_bul;
        BOOST_TEST_CHECK(player.GetPistolBullets() == 10);
        Bullets r_bul(15, BulletType::kRifle);
        player += r_bul;
        BOOST_TEST_CHECK(player.GetRifleBullets() == 15);
        FirstAidKit first_aid_kit(58);
        BOOST_TEST_CHECK(player.GetFirstAidKits() == 0);
        player += first_aid_kit;
        BOOST_TEST_CHECK(player.GetFirstAidKits() == 58);
        first_aid_kit = FirstAidKit(-12);
        player += first_aid_kit;
        BOOST_TEST_CHECK(player.GetFirstAidKits() == 46);
        BOOST_TEST_CHECK(player.Attack() == 0);
        Sword sw1(10);
        player += sw1;
        BOOST_TEST_CHECK(player.Attack() == 10);
    }
BOOST_AUTO_TEST_SUITE_END()