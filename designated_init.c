/*
this file is part of c-notes
https://github.com/duddel/c-notes

C - designated initializers
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
