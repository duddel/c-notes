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

#include "template.h"

// generic implementation of VecA<T, N> constructor
template <class T, unsigned int N>
VecA<T, N>::VecA(T init)
{
    for (unsigned int i = 0; i < N; i++)
        _v[i] = init;
}

// generic implementation of VecA<T, N>::sum()
template <class T, unsigned int N>
T VecA<T, N>::sum()
{
    T sum = _v[0];
    for (unsigned int i = 1; i < N; i++)
        sum += _v[i];
    return sum;
}

// the generic implementation of VecA<T, N> is not part of template.h.
// therefore, implementations can not be generated on demand (in user-code).
// only the implementations explicitly listed here are generated:
template class VecA<float, 3>;
template class VecA<int, 2>;
