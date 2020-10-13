#include <boost/test/unit_test.hpp>

#include "etu_game/objects/cell.h"
#include "etu_game/objects/field.h"
#include "etu_game/objects/field_iterator.h"
#include "etu_game/types/etu_game_exception.h"

using namespace etu_game;
using namespace objects;
using namespace types;

BOOST_AUTO_TEST_SUITE(suite_1, * boost::unit_test::label("test1"))
    BOOST_AUTO_TEST_CASE(test_1,
        * boost::unit_test::description("Testing Cell"))
    {
        Cell cell;
        BOOST_TEST_REQUIRE(cell.GetType() == types::CellType::kEmpty);
        cell.SetType(types::CellType::kBlock);
        BOOST_TEST_REQUIRE(cell.GetType() == types::CellType::kBlock);
        Cell cell2 = cell;
        BOOST_TEST_REQUIRE(cell2.GetType() == types::CellType::kBlock);
        Cell cell3(types::CellType::kEntry);
        BOOST_TEST_REQUIRE(cell3.GetType() == types::CellType::kEntry);
    }
    BOOST_AUTO_TEST_CASE(test_2,
     * boost::unit_test::description("Testing EtuGameException and Field constructor"))
    {
        BOOST_REQUIRE_THROW(Field& f = Field::GetInstance(-12,13), EtuGameException);
        BOOST_REQUIRE_THROW(Field& f = Field::GetInstance(12,-67), EtuGameException);
        BOOST_REQUIRE_THROW(Field& f = Field::GetInstance(0,13), EtuGameException);
        BOOST_REQUIRE_THROW(Field& f = Field::GetInstance(48,0), EtuGameException);
    }
    BOOST_AUTO_TEST_CASE(test_3,
     * boost::unit_test::description("Testing Field"))
    { 
        int width = 14, height = 5;
        Field& f =Field::GetInstance(height, width);
        BOOST_TEST_REQUIRE(height == f.GetHeight());
        BOOST_TEST_REQUIRE(width == f.GetWidth());
        Field& f2 =Field::GetInstance(8,8);
        BOOST_TEST_REQUIRE(height == f.GetHeight());
        BOOST_TEST_REQUIRE(width == f.GetWidth());
        // FIXME: do unittest for CheckInvariant() when it will be possible to load the map
        BOOST_TEST_REQUIRE(f2.CheckInvariant());
    }
    BOOST_AUTO_TEST_CASE(test_4,
     * boost::unit_test::description("Testing FieldIterator"))
    {
        //FIXME: Do Field with pointer
        Field& f2 =Field::GetInstance(8,8);
        //BOOST_TEST_REQUIRE(f2.GetHeight() == 8);
        //BOOST_TEST_REQUIRE(f2.GetWidth() == 8);
        /* FIXME: 
         *  1) Fix postfix increment
         *  2) do good unittest for when it will be possible to load the map
         */
        for(FieldIterator iter(f2); iter(); iter++){
            BOOST_TEST_REQUIRE(iter.CurrentItem().GetType() == types::CellType::kEmpty);
        }
        BOOST_REQUIRE_THROW({
                for(FieldIterator iter(f2);;iter++){}
                BOOST_FAIL("Excepcted exception");
            }, EtuGameException);
    }
BOOST_AUTO_TEST_SUITE_END()