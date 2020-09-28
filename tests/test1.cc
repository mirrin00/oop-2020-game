#include "catch.hpp"

#include "etu_game/objects/cell.h"
#include "etu_game/objects/field.h"
#include "etu_game/objects/field_iterator.h"
#include "etu_game/types/etu_game_exception.h"

using namespace etu_game;
using namespace objects;
using namespace types;

TEST_CASE("Test 1: Testing Cell, EtuGameException, Field, FieldIterator", "[test1]"){
    SECTION("Testing Cell"){
        Cell cell;
        REQUIRE(cell.GetType() == types::CellType::kEmpty);
        cell.SetType(types::CellType::kBlock);
        REQUIRE(cell.GetType() == types::CellType::kBlock);
        Cell cell2 = cell;
        REQUIRE(cell2.GetType() == types::CellType::kBlock);
        Cell cell3(types::CellType::kEntry);
        REQUIRE(cell3.GetType() == types::CellType::kEntry);
    }
    SECTION("Testing EtuGameException and Field constructor"){
        try{
            Field& f = Field::GetInstance(-12,13);
            REQUIRE(false);
        }catch(EtuGameException& e){}
        try{
            Field& f = Field::GetInstance(12,-67);
            REQUIRE(false);
        }catch(EtuGameException& e){}
        try{
            Field& f = Field::GetInstance(0,13);
            REQUIRE(false);
        }catch(EtuGameException& e){}
        try{
            Field& f = Field::GetInstance(48,0);
            REQUIRE(false);
        }catch(EtuGameException& e){}
    }
    SECTION("Testing Field"){
        int width = 14, height = 5;
        Field& f =Field::GetInstance(height, width);
        REQUIRE(height == f.GetHeight());
        REQUIRE(width == f.GetWidth());
        Field& f2 =Field::GetInstance(8,8);
        REQUIRE(height == f.GetHeight());
        REQUIRE(width == f.GetWidth());
        // FIXME: do unittest for CheckInvariant() when it will be possible to load the map
        REQUIRE(f2.CheckInvariant());
    }
    SECTION("Testing FieldIterator"){
        Field& f2 =Field::GetInstance(8,8);
        /* FIXME: 
         *  1) Fix postfix increment
         *  2) do good unittest for when it will be possible to load the map
         */
        for(FieldIterator iter(f2); iter(); iter++){
            REQUIRE(iter.CurrentItem().GetType() == types::CellType::kEmpty);
        }
        try{
            for(FieldIterator iter(f2);;iter++){}
            REQUIRE(false);
        }catch(EtuGameException& e){}
    }
}