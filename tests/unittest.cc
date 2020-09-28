#include "unittest.h"

void UnitTest::Assert(){
    assert(0);
}

void UnitTest::AssertEqual(int a, int b){
    assert(a == b);
}

void UnitTest::AssertNotEqual(int a, int b){
    assert(a != b);
}

void UnitTest::AssertGreaterEqual(int a, int b){
    assert(a >= b);
}

void UnitTest::AssertLessEqual(int a, int b){
    assert(a <= b);
}

void UnitTest::AssertGreater(int a, int b){
    assert(a > b);
}
void UnitTest::AssertLess(int a, int b){
    assert(a < b);
}