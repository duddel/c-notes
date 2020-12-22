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
#include <typeinfo>
#include <cstdio> // printf()

struct A { };
typedef A AT;
struct B : A { };
namespace Aspace
{
    struct A { };
}

template <class T>
void printTypeInfo()
{
    const std::type_info &tT = typeid(T);
    std::printf("%s (%zX)\n", tT.name(), tT.hash_code());
}

int main()
{
    // the typeid() operator returns type information (std::type_info):
    //   name: implementation defined name of a type
    //   hash: since C++11, guaranteed to be identical for same types

    printTypeInfo<A>();
    printTypeInfo<A &>();       // same as A
    printTypeInfo<AT>();        // same as A
    printTypeInfo<A *>();       // pointer
    printTypeInfo<B>();         // derived type
    printTypeInfo<Aspace::A>(); // also work for namespaced types
    printTypeInfo<int>();
}
