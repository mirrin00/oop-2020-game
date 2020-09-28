#include <cassert>

class UnitTest{
public:
    static void Assert();
    static void AssertEqual(int a, int b);
    static void AssertNotEqual(int a, int b);
    static void AssertGreaterEqual(int a, int b);
    static void AssertLessEqual(int a, int b);
    static void AssertGreater(int a, int b);
    static void AssertLess(int a, int b);
};