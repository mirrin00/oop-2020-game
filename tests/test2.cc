#include "catch.hpp"

#include "etu_game/objects/sword.h"
#include "etu_game/objects/item.h"
#include "etu_game/objects/hands.h"
#include "etu_game/objects/health_potion.h"
#include "etu_game/objects/coin.h"

using namespace etu_game;
using namespace objects;

TEST_CASE("Testing Items: Item, Sword, Hands, HealthPotion and Coin","[test2]"){
    SECTION("Sword and Hands"){
        Sword sw1(3,5,6);
        sw1.SetCanUse(true);
        REQUIRE(sw1.GetHeightPosition() == 5);
        REQUIRE(sw1.GetWidthPosition() == 6);
        REQUIRE(sw1.Attack() == 3);
        Sword sw2 = sw1;
        REQUIRE(sw2.GetHeightPosition() == 5);
        REQUIRE(sw2.GetWidthPosition() == 6);
        REQUIRE(sw2.Attack() == 3);
        sw2.SetWidthPosition(42);
        REQUIRE(sw2.GetWidthPosition() == 42);
        Hands hands;
        std::unique_ptr<Weapon> weapon = Hands().clone();
        REQUIRE(weapon->Attack() == 0);
        weapon = sw2.clone();
        REQUIRE(weapon->Attack() == 3);
    }
    //TODO: tests for HP and Coin, before do copy operator to them
}