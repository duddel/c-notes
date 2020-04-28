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

#include <cstdio> // printf()
//#include <cstddef> // NULL

void func(int i)   { printf("func(int i),   i = %i\n", i); }
void func(char *i) { printf("func(char *i), i = %p\n", i); }

int main()
{
    // since C++11, nullptr can be used to express that an actual null pointer
    // is passed, instead of an 0 integer
    func(nullptr);      // calls func(char *i)

    // most likely, NULL is defined like
    //    #define NULL 0
    // or
    //    #define NULL 0L
    func(0);            // calls func(int i)
//  func(0L);           // error: ambiguous call of func(). both func(int i)
                        // and func(char *i) are equal candidates to be called
//  func(NULL);         // most likely, one of the two cases above
}
