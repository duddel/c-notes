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

#include <stdarg.h>
#include <stdio.h> // printf()

#define SUM_INT(...) sumi(__VA_ARGS__)

int sumi(int count, ...);
int sumi2(int count, ...);
int sumi3(int count, ...);
int vsumi(int count, va_list va);

int main()
{
    // a variadic function is a function with variable number of arguments
    // printf() itself is such a function

    // sumi() is a variadic function
    printf("sumi(): %i\n", sumi(3, 1, 2, 3));

    // sumi2() forwards the variable arguments to vsumi()
    printf("sumi2(): %i\n", sumi2(3, 1, 2, 3));

    // sumi3() copies and forwards the variable arguments to vsumi()
    printf("sumi3(): %i\n", sumi3(3, 1, 2, 3));

    // SUM_INT is a variadic macro
    printf("SUM_INT(): %i\n", SUM_INT(3, 1, 2, 3));

    return 0;
}

int sumi(int count, ...)
{
    va_list args;
    va_start(args, count); // access arguments following argument count
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        /* assuming all arguments are int. printf() parses
        the format string to determine the argument types. */
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

int sumi2(int count, ...)
{
    va_list args;
    va_start(args, count);
    vsumi(count, args);
    va_end(args);
}

int sumi3(int count, ...)
{
    va_list args;
    va_list args2;
    va_start(args, count);
    va_copy(args2, args); // since C99
    vsumi(count, args2);
    va_end(args); // args unused
    va_end(args2);
}

int vsumi(int count, va_list args)
{
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += va_arg(args, int);
    }
    return sum;
}
