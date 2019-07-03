/*
this file is part of c-notes
https://github.com/duddel/c-notes

C - variadic functions
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
