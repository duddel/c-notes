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
#ifndef C_NOTES_TEMPLATE_H
#define C_NOTES_TEMPLATE_H

// template implementations must be visible to the compiler,
// so that actual implementations can be generated on demand.
template <class T, class U>
T add(T a, U b)
{
    return a + (T)b;
}

// VecA is implemented in template_impl.cpp. the usage of VecA
// is restricted to only the implementations mentioned at the
// end of template_impl.cpp.
// template parameters can also be constants, such as N
template <class T, unsigned int N>
class VecA
{
public:
    T _v[N];
    VecA(T init);
    T sum();
};

// the class template VecB is defined and implemented
// in template.h. the class also has a partially specialized
// implementation for N=1, see below
template <class T, unsigned int N>
class VecB
{
public:
    T _v[N];
    VecB(T init)
    {
        for (unsigned int i = 0; i < N; i++)
            _v[i] = init;
    }
    T sum()
    {
        T sum = _v[0];
        for (unsigned int i = 1; i < N; i++)
            sum += _v[i];
        return sum;
    }
};

// partial specialization for N=1: VecB<T, 1>
template <class T>
class VecB<T, 1>
{
public:
    T _v;
    VecB(T init) { _v = init; }
    T inv() { return -_v; }
};

#endif
