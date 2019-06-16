/*
this file is part of c-notes
https://github.com/duddel/c-notes

C++11 - braced initializer lists
*/

#include <map>

struct A
{
    float f;
    int i;
    A(float _f, int _i) : f(_f), i(_i) {}
};

struct B
{
    float f;
    int i;
};

int main()
{
    // since C++11, braced initializer lists can be used for object creation

    A a1 = {1.0f, 1}; // initialized with constructor
//  A a2 = {1.0f};    // illegal, no compatible constructor
    B b1 = {1.0f, 1}; // initialized without constructor
    B b2 = {1.0f};    // legal, b2.i zero initialized

    // also works nested and with containers (such as map), like so:
    std::map<int, A> aMap = {
        {1, {1.0f, 1}},
        {2, {2.0f, 2}}};

    // and with new:
    A *aPtr = new A{1.0f, 1};

    return 0;
}
