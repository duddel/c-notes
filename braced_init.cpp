/*
Copyright (c) 2019 Alexander Scholz

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
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
