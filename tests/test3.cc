#include "catch.hpp"

#include "etu_game/objects/sword.h"
#include "etu_game/objects/item.h"
#include "etu_game/objects/hands.h"
#include "etu_game/objects/health_potion.h"
#include "etu_game/objects/coin.h"
#include "etu_game/objects/player.h"

using namespace etu_game;
using namespace objects;

TEST_CASE("Testing Player", "[test3]"){
    int h_pos = 43, w_pos = 41, health = 100;
    Player player(health, h_pos, w_pos);
    SECTION("Moving"){
        REQUIRE(player.GetHealth() == health);
        REQUIRE(player.GetHeightPosition() == h_pos);
        REQUIRE(player.GetWidthPosition() == w_pos);
        player.Move(15,-98);
        REQUIRE(player.GetHeightPosition() == h_pos + 15);
        REQUIRE(player.GetWidthPosition() == w_pos - 98);
        player.SetWidhtPosition(0);
        REQUIRE(player.GetWidthPosition() == 0);
        player.SetHeightPosition(0);
        REQUIRE(player.GetHeightPosition() == 0);
    }
    SECTION("Items"){
        REQUIRE(player.GetCoins() == 0);
        Coin coin(25);
        coin.SetCanUse(true);
        player += coin;
        REQUIRE(player.GetCoins() == 25);
        HealthPotion potion(-58);
        potion.SetCanUse(true);
        player += potion;
        REQUIRE(player.GetHealth() == 42);
        potion = HealthPotion(1);
        potion.SetCanUse(true);
        player += potion;
        REQUIRE(player.GetHealth() == 43);
        REQUIRE(player.Attack() == 0);
        Sword sw1(10);
        sw1.SetCanUse(true);
        player += sw1;
        REQUIRE(player.Attack() == 10);
    }
}