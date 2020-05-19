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
