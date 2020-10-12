#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

#include "etu_game/logic/logger.h"
#include "etu_game/logic/publisher.h"
#include "etu_game/logic/subscriber.h"

#include "etu_game/objects/sword.h"
#include "etu_game/objects/health_potion.h"
#include "etu_game/objects/coin.h"
#include "etu_game/objects/player.h"

using namespace etu_game;
using namespace objects;
using namespace logic;

std::string get_string_without_time(std::string file_name){
    std::ifstream file(file_name);
    std::string str;
    bool in_bracket = false;
    while(file){
        char c = file.get();
        if(c == '[') in_bracket = true;
        if(file && !in_bracket) str += c;
        if(c == ']') in_bracket = false;
    }
    file.close();
    return str;
}

BOOST_AUTO_TEST_SUITE(suite_4,  * boost::unit_test::label("test4"))

BOOST_AUTO_TEST_CASE(test_1,
     * boost::unit_test::description("Testing Logger, Publisher and Subscriber"))
    {
        boost::test_tools::output_test_stream out;

        Player player(100,13,11);
        Sword sword(9,0,3);
        sword.SetCanUse(true);
        Coin coin(7,-9,-4);
        HealthPotion hp(-3,7,5);
        hp.SetCanUse(true);
        hp.SetOnField(false);
        {
            Logger logger("logger_test_0.testing", out);
            BOOST_TEST_CHECK(logger.IsWriteInStream() == true);
            logger.SetWriteInStream(false);
            BOOST_TEST_CHECK(logger.IsWriteInStream() == false);
            logger.SetWriteInStream(true);
            // FIXME: Add logging to player
            //logger.WriteLog<Player>(player);
            logger.WriteLog<Sword>(sword);
            logger.WriteLog<Coin>(coin);
            logger.WriteLog<HealthPotion>(hp);
        }
        std::ifstream file("logger_test_0.testing");
        if(!file.is_open()) BOOST_FAIL("Can't open logger_test_0.testing");
        std::string str_for_out, str_for_check;
        bool in_bracket = false;
        while(file){
            char c = file.get();
            if(c == '[') in_bracket = true;
            if(file){
                str_for_out += c;
                if(!in_bracket) str_for_check += c;
            }
            if(c == ']') in_bracket = false;
        }
        file.close();
        std::string str_check = "Sword:\n";
        str_check += "    Height position: 0\n";
        str_check += "    Width position: 3\n";
        str_check += "    On field: 1\n";
        str_check += "    Can use: 1\n";
        str_check += "    Damage: 9\n";
        str_check += "Coin:\n";
        str_check += "    Height position: -9\n";
        str_check += "    Width position: -4\n";
        str_check += "    On field: 1\n";
        str_check += "    Can use: 0\n";
        str_check += "    Count: 7\n";
        str_check += "HealthPotion:\n";
        str_check += "    Height position: 7\n";
        str_check += "    Width position: 5\n";
        str_check += "    On field: 0\n";
        str_check += "    Can use: 1\n";
        str_check += "    Health change: -3\n";
        BOOST_TEST_REQUIRE(out.is_equal(str_for_out));
        BOOST_TEST_REQUIRE(str_check == str_for_check);
        std::string str_check1 = str_check.substr(0, str_check.find("Coin:"));
        std::string str_check2 = str_check.substr(0, str_check.find("HealthPotion:"));
        {
            Logger lg1("logger1_test0.testing"),
                lg2("logger2_test0.testing"),
                lg3("logger3_test0.testing");
            Subscriber sub1(lg1), sub2(lg2), sub3(lg3);
            Publisher pub;
            pub.Subscribe(sub1);
            pub.Subscribe(sub2);
            pub.Subscribe(sub3);
            pub.Notify<Sword>(sword);
            pub.Unsubscribe(sub1);
            pub.Notify<Coin>(coin);
            pub.Unsubscribe(sub2);
            pub.Notify<HealthPotion>(hp);
        }
        std::string str1 = get_string_without_time("logger1_test0.testing"),
                str2  = get_string_without_time("logger2_test0.testing"),
                str3  = get_string_without_time("logger3_test0.testing");
        BOOST_TEST_REQUIRE(str1 == str_check1);
        BOOST_TEST_REQUIRE(str2 == str_check2);
        BOOST_TEST_REQUIRE(str3 == str_check);
    }

BOOST_AUTO_TEST_SUITE_END()