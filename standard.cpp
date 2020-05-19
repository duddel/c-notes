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
#include <cstdio> // printf()

int main()
{
    // a C++ compiler defines the __cplusplus macro
    // the __cplusplus macro also reports the C++ standard
    // handle with care, compilers reporting wrong values are not rare!

    switch (__cplusplus)
    {
    case 1:
        printf("pre C++98, __cplusplus = 1\n");
        break;
    case 199711L:
        printf("C++98, __cplusplus = 199711L\n");
        break;
    case 201103L:
        printf("C++11, __cplusplus = 201103L\n");
        break;
    case 201402L:
        printf("C++14, __cplusplus = 201402L\n");
        break;
    case 201703L:
        printf("C++17, __cplusplus = 201703L\n");
        break;
    default:
        printf("C++ unknown, __cplusplus = %liL\n", __cplusplus);
        break;
    }

    return 0;
}
