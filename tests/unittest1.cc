#include <iostream>
#include "etu_game/objects/cell.h"
#include "etu_game/objects/field.h"
#include "etu_game/objects/field_iterator.h"
#include "etu_game/types/etu_game_exception.h"
#include "unittest.h"

using namespace etu_game;
using namespace objects;
using namespace types;
using namespace std;

// FIXME: may be do with abort()?

int main(){
    cout << "UnitTest 1: Testing Cell, EtuGameException, Field, FieldIterator...\n";
    {
        cout << "   Testing Cell...\n";
        Cell cell;
        UnitTest::AssertEqual(cell.GetType(), types::CellType::kEmpty);
        cell.SetType(types::CellType::kBlock);
        UnitTest::AssertEqual(cell.GetType(), types::CellType::kBlock);
        Cell cell2 = cell;
        UnitTest::AssertEqual(cell2.GetType(), types::CellType::kBlock);
        Cell cell3(types::CellType::kEntry);
        UnitTest::AssertEqual(cell3.GetType(), types::CellType::kEntry);
        cout << "   Cell testing done.\n";
    }
    {
        cout << "   Testing EtuGameException and Field constructor...\n";
        try{
            Field& f = Field::GetInstance(-12,13);
            UnitTest::Assert();
        }catch(EtuGameException& e){}
        try{
            Field& f = Field::GetInstance(12,-67);
            UnitTest::Assert();
        }catch(EtuGameException& e){}
        try{
            Field& f = Field::GetInstance(0,13);
            UnitTest::Assert();
        }catch(EtuGameException& e){}
        try{
            Field& f = Field::GetInstance(48,0);
            UnitTest::Assert();
        }catch(EtuGameException& e){}
        cout << "   EtuGameException testing done.\n";
    }
    {
        cout << "   Testing Field...\n";
        int width = 14, height = 5;
        Field& f =Field::GetInstance(height, width);
        UnitTest::AssertEqual(height, f.GetHeight());
        UnitTest::AssertEqual(width, f.GetWidth());
        Field& f2 =Field::GetInstance(8,8);
        UnitTest::AssertEqual(height, f.GetHeight());
        UnitTest::AssertEqual(width, f.GetWidth());
        // FIXME: do unittest for CheckInvariant() when it will be possible to load the map
        if( !f2.CheckInvariant() ) UnitTest::Assert();
        cout << "   Field testing done.\n";
    }
    {
        Field& f2 =Field::GetInstance(8,8);
        cout << "   Testing FieldIterator...\n";
        /* FIXME: 
         *  1) prefix increment to postfix increment (completed)
         *  2) do good unittest for when it will be possible to load the map
         */
        for(FieldIterator iter(f2); iter(); iter++){
            UnitTest::AssertEqual(iter.CurrentItem().GetType(), types::CellType::kEmpty);
        }
        try{
            for(FieldIterator iter(f2);;iter++){}
            UnitTest::Assert();
        }catch(EtuGameException& e){}
        cout << "   FieldIterator testing done.\n";
    }
    cout << "UnitTest 1 done.\n";
    return 0;
}
