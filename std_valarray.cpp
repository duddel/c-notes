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
#include <cstdio>   // printf()
#include <iostream> // cout
#include <valarray>
#include <vector>

template <class T>
void printValarray(const char *info, const std::valarray<T> &varr)
{
    std::cout << info << ": ";
    for (T const &a : varr)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

template <class T>
T calcFunc(const T &val)
{
    return val * val;
}

int main()
{
    std::vector<float> values2 = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f};
    float values3[] = {1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f};

    // valarrays are used to perform element-wise operations on numeric values

    // valarray with initial value
    std::valarray<int> varr1(5, 10);
    printValarray("varr1", varr1);

    // valarray from std::vector
    std::valarray<float> varr2(values2.data(), values2.size());
    printValarray("varr2", varr2);

    // valarray from C-style array
    std::valarray<float> varr3(values3, sizeof(values3) / sizeof(values3[0]));
    printValarray("varr3", varr3);

    // operations on valarray
    printf("varr2.sum(): %f\n", varr2.sum());
    printf("varr2.min(): %f\n", varr2.min());
    printf("varr2.max(): %f\n", varr2.max());
    printValarray("varr2.cshift(2)", varr2.cshift(2));
    printValarray("varr2.shift(-2)", varr2.shift(-2));

    // apply function to each element
    printValarray("varr2.apply(calcFunc)", (std::valarray<float>)varr2.apply(calcFunc));

    // math functions
    printValarray("std::pow(varr2, 3.0f)", (std::valarray<float>)std::pow(varr2, 3.0f));

    // operators
    varr2 *= 10.0f;
    printValarray("varr2 after *= 10.0f", varr2);
    printValarray("varr2 * varr3", (std::valarray<float>)(varr2 * varr3));

    // slicing
    // std::slice_array references the original values of the valarray.
    // therefore, it can be used to modify the original valarray data
    std::slice_array<float> sarr3_0 = varr3[std::slice(0, 3, 2)];
    std::slice_array<float> sarr3_1 = varr3[std::slice(1, 3, 2)];
    sarr3_0 *= std::valarray<float>(100.0f, 3);
    sarr3_1 = -99.0f;
    printValarray("varr3 after slicing", varr3);

    // creating a valarray from the slice_array copies the referenced
    // values to the new valarray object
    std::valarray<float> varr3s0(sarr3_0);
    printValarray("varr3s0 from slice_array", varr3s0);

    // convert valarray back to std::vector
    std::vector<float> vecFromValarr(std::begin(varr2), std::end(varr2));

    return 0;
}
