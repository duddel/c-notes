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
struct A
{
    int i;
    float f;
};

struct B
{
    struct A a;
};

int main()
{
    // designated initializers are part of C, support in C++ is very limited!
    // elements that are not designated in the braces get zero initialized

    struct A a1 = {.i = 1, .f = 2.0f}; // all members initialized
    struct A a2 = {.i = 1};            // not all members, but first declared member(s) initialized
    struct A a3 = {.f = 2.0f};         // not all members, not first declared member(s) initialized
    struct A a4 = {.i = 2, 2.0f};      // mixed initialization with and without designator
    struct A a5 = {.f = 2.0f, .i = 1}; // all members initialized, but not in declaration order
    struct B b1 = {.a.i = 1};          // nested
    int arr[3] = {[1] = 2};            // also works with arrays

    return 0;
}
