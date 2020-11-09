#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

#include "time_lost/logic/logger.h"
#include "time_lost/logic/publisher.h"

#include "time_lost/objects/sword.h"
#include "time_lost/objects/health_potion.h"
#include "time_lost/objects/coin.h"
#include "time_lost/objects/player.h"

#include "time_lost/objects/field.h"

using namespace time_lost;
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

        Player player(100,{13,11});
        Sword sword(9,{0,3});
        sword.SetCanUse(true);
        Coin coin(7,{-9,-4});
        HealthPotion hp(-3,{7,5});
        hp.SetCanUse(true);
        hp.SetOnField(false);
        {
            Logger logger("logger_test1.testing", out);
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
        std::ifstream file("logger_test1.testing");
        if(!file.is_open()) BOOST_FAIL("Can't open logger_test1.testing");
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
        str_check += "    Position:{y=3, x=0}\n";
        str_check += "    On field: 1\n";
        str_check += "    Can use: 1\n";
        str_check += "    Damage: 9\n";
        str_check += "Coin:\n";
        str_check += "    Position:{y=0, x=0}\n";
        str_check += "    On field: 1\n";
        str_check += "    Can use: 0\n";
        str_check += "    Count: 7\n";
        str_check += "HealthPotion:\n";
        str_check += "    Position:{y=5, x=7}\n";
        str_check += "    On field: 0\n";
        str_check += "    Can use: 1\n";
        str_check += "    Health change: -3\n";
        BOOST_TEST_REQUIRE(out.is_equal(str_for_out));
        BOOST_TEST_REQUIRE(str_check == str_for_check);
        std::string str_check1 = str_check.substr(0, str_check.find("Coin:"));
        std::string str_check2 = str_check.substr(0, str_check.find("HealthPotion:"));
        {
            std::shared_ptr<Logger> lg1 = std::make_shared<Logger>("logger1_test1.testing"),
                lg2 = std::make_shared<Logger>("logger2_test1.testing"),
                lg3 = std::make_shared<Logger>("logger3_test1.testing");
            Publisher pub;
            pub.Subscribe(lg1);
            pub.Subscribe(lg2);
            pub.Subscribe(lg3);
            pub.Notify<Sword>(sword);
            pub.Unsubscribe(lg1);
            pub.Notify<Coin>(coin);
            pub.Unsubscribe(lg2);
            pub.Notify<HealthPotion>(hp);
        }
        std::string str1 = get_string_without_time("logger1_test1.testing"),
                str2  = get_string_without_time("logger2_test1.testing"),
                str3  = get_string_without_time("logger3_test1.testing");
        BOOST_TEST_REQUIRE(str1 == str_check1);
        BOOST_TEST_REQUIRE(str2 == str_check2);
        BOOST_TEST_REQUIRE(str3 == str_check);
    }

 BOOST_AUTO_TEST_CASE(test_2,
     * boost::unit_test::description("Testing Logging"))
    {
        boost::test_tools::output_test_stream out;
        Field f = Field(3,4);
        out << f;
        std::string str("Field:\n");
        str += "    Height: 3\n";
        str += "    Width: 4\n";
        str += "    Cells:\n";
        str += "0000\n0000\n0000\n";
        //FIXME: Complete test after solving problem with field
        BOOST_TEST_REQUIRE(out.is_equal(str));
        {
            std::shared_ptr<Logger> lg1 = std::make_shared<Logger>("logger1_test2.testing"),
                lg2 = std::make_shared<Logger>("logger2_test2.testing"),
                lg3 = std::make_shared<Logger>("logger3_test2.testing");
            Player player(100,{6,6});
            Coin coin(3,{8,-9});
            Sword sword(9);
            player.Subscribe(lg1);
            player.Subscribe(lg2);
            coin.Subscribe(lg2);
            coin.Subscribe(lg3);
            coin.Subscribe(lg1);
            sword.Subscribe(lg3);
            sword.Subscribe(lg1);
            player.Move({3,-2});
            coin.SetCanUse(true);
            sword.SetPosition({6,0});
        }
        std::string str1 = get_string_without_time("logger1_test2.testing"),
                str2  = get_string_without_time("logger2_test2.testing"),
                str3  = get_string_without_time("logger3_test2.testing");
        std::string str_check1("Player:\n");
        str_check1 += "Essence:\n";
        str_check1 += "    Position:{y=4, x=9}\n";;
        str_check1 += "    Health: 100\n";
        str_check1 += "Hands:\n";
        str_check1 += "    Attack: 0\n";
        str_check1 += "    Coins: 0\n";
        str_check1 += "Coin:\n";
        str_check1 += "    Position:{y=0, x=8}\n";
        str_check1 += "    On field: 1\n";
        str_check1 += "    Can use: 1\n";
        str_check1 += "    Count: 3\n";
        str_check1 += "Sword:\n";
        str_check1 += "    Position:{y=0, x=6}\n";
        str_check1 += "    On field: 1\n";
        str_check1 += "    Can use: 0\n";
        str_check1 += "    Damage: 9\n";
        std::string str_check2 = str_check1.substr(0,str_check1.find("Sword")); 
        std::string str_check3 = str_check1.substr(str_check1.find("Coin:"));
        BOOST_TEST_REQUIRE(str1 == str_check1);
        BOOST_TEST_REQUIRE(str2 == str_check2);
        BOOST_TEST_REQUIRE(str3 == str_check3);
    }
    //TODO: Test output for all classes

BOOST_AUTO_TEST_SUITE_END()