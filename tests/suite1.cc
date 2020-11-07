#include <boost/test/unit_test.hpp>

#include "time_lost/objects/cell.h"
#include "time_lost/objects/field.h"
#include "time_lost/objects/field_iterator.h"
#include "time_lost/types/time_lost_exception.h"

using namespace time_lost;
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
     * boost::unit_test::description("Testing TimeLostException and Field constructor"))
    {
        BOOST_REQUIRE_THROW(Field f = Field(-12,13), TimeLostException);
        BOOST_REQUIRE_THROW(Field f = Field(12,-67), TimeLostException);
        BOOST_REQUIRE_THROW(Field f = Field(0,13), TimeLostException);
        BOOST_REQUIRE_THROW(Field f = Field(48,0), TimeLostException);
    }
    BOOST_AUTO_TEST_CASE(test_3,
     * boost::unit_test::description("Testing Field"))
    { 
        int width = 14, height = 5;
        Field f =Field(height, width);
        BOOST_TEST_REQUIRE(height * LOCATION_SIZE == f.GetHeight());
        BOOST_TEST_REQUIRE(width * LOCATION_SIZE == f.GetWidth());
        Field f2 =Field(8,8);
        BOOST_TEST_REQUIRE(8  * LOCATION_SIZE== f2.GetHeight());
        BOOST_TEST_REQUIRE(8  * LOCATION_SIZE== f2.GetWidth());
    }
    BOOST_AUTO_TEST_CASE(test_4,
     * boost::unit_test::description("Testing FieldIterator"))
    {
        Field f2 =Field(8,8);
        //BOOST_TEST_REQUIRE(f2.GetHeight() == 8);
        //BOOST_TEST_REQUIRE(f2.GetWidth() == 8);
        /* FIXME: 
         *  1) Fix postfix increment
         *  2) do good unittest for when it will be possible to load the map
         *  3) !iter() !!!
         */
        for(FieldIterator iter(f2); iter(); iter++){
            BOOST_TEST_REQUIRE(iter.CurrentItem().GetType() == types::CellType::kEmpty);
        }
        BOOST_REQUIRE_THROW({
                for(FieldIterator iter(f2);;iter++){}
                BOOST_FAIL("Excepcted exception");
            }, TimeLostException);
    }
BOOST_AUTO_TEST_SUITE_END()