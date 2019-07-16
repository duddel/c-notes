/*
this file is part of c-notes
https://github.com/duddel/c-notes

C, C++ - function pointers
*/

#include <stdio.h> // printf()

int add(int i, int j) { return i + j; }
int mul(int i, int j) { return i * j; }

// _outputInt is a function pointer
void (*_outputInt)(int);

// registerOutputInt() takes a function pointer
void registerOutputInt(void (*func)(int))
{
   _outputInt = func;
}

void printInt(int i) { printf("%i\n", i); }

int main()
{
   // "register" a function, commonly done with callbacks
   registerOutputInt(printInt);

   // this is an array of function pointers
   int (*intOps[])(int, int) = {add, mul};

   _outputInt(intOps[0](4, 5));
   _outputInt(intOps[1](4, 5));

   return 0;
}
