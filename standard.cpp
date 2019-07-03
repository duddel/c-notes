/*
this file is part of c-notes
https://github.com/duddel/c-notes

C++ - the __cplusplus macro
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
        printf("C++17, __cplusplus =201703L\n");
        break;
    default:
        printf("C++ unknown, __cplusplus = %liL\n", __cplusplus);
        break;
    }

    return 0;
}
