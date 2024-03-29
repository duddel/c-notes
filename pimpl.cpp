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
#include "pimpl.h"

class A::impl
{
public:
    int data;
    impl(int data) : data(data) {}
    ~impl() {}
    int multiply(int factor) { return data * factor; }
};

A::A(int data) : pimpl{new impl{data}} {}
A::~A() {}

int A::calc(int factor)
{
    return pimpl->multiply(factor);
}

int main()
{
    A a(16);
    a.calc(4); // 64
}
