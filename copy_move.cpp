/*
Copyright (c) 2020 Alexander Scholz

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
#include <cstdio>  // printf()
#include <utility> // std::move()

class A
{
public:
    int *data;

    A(int i) { data = new int(i); }
    ~A() { delete data; }

    A(const A &a) // copy ctor
    {
        data = new int(*(a.data)); // allocate new memory and make
                                   // a copy of the actual data
    }

    A(A &&a) // move ctor
    {
        data = a.data;    // steal data by copying the pointer...
        a.data = nullptr; // ...and prevent deletion of data if
                          // moved-from object ist destroyed
    }
};

int main()
{
    // a copy constructor makes a copy of the argument.
    //   a move constructor makes a "shallow copy" of the argument
    // and "transfers" the data, preventing unnecessary copies.
    // this allows functions to return objects without copying.
    //   if an object handles dynamic data or other resources,
    // the constructors have to take this into account,
    // as done here in class A.

    A *a1 = new A(2);
    printf("a1.data -> %i @ 0x%p\n", *a1->data, a1->data);

    // copy a1 to a2, a3
    A a2 = A(*a1);
    A a3 = A(*a1);

    // move a1 to a4
    A a4 = A(std::move(*a1));
    // after moving to a4, a1 is useless
    delete a1;

    printf("a2.data -> %i @ 0x%p (copy of a1)\n", *a2.data, a2.data);
    printf("a3.data -> %i @ 0x%p (copy of a1)\n", *a3.data, a3.data);
    printf("a4.data -> %i @ 0x%p (moved from a1)\n", *a4.data, a4.data);

    // ToDo: mention copy/move assignment operators
    // ToDo: mention preventing copying by "deleting" copy ctor and operator
}
