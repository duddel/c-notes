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
#include <cstdio>    // printf()
#include <iostream>  // cout
#include <algorithm> // sort()
#include <array>

template <class T, unsigned int N>
void printArray(const std::array<T, N> &arr)
{
    for (T const &a : arr)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // C-style arrays are cumbersome to use, as they appear
    // as pointers only, and their size information is lost
    int cArr[3] = {1, 2, 3};
    printf("cArr     = 0x%p\n", cArr);
    printf("&cArr[0] = 0x%p\n", &cArr[0]);

    // since C++11, std::array is an alternative
    std::array<int, 8> arr = {1, 5, 6, 7, 4, 2, 9, 8};

    // they can be accessed via []
    printf("arr[1] = %i\n", arr[1]);

    // they can be accessed via at(), which performs bounds checking
    printf("arr.at(1) = %i\n", arr.at(1));

    // their underlying data is contiguous in memory
    for (auto i = 0; i < arr.size(); i++) // they also know their size
    {
        std::cout << arr.data()[i] << " ";
    }
    std::cout << std::endl;

    // they can be sorted
    std::sort(arr.begin(), arr.end());

    // they can be passed around
    printArray(arr);

    // they can be multi-dimensional
    std::array<std::array<int, 3>, 4> arr33 = {{{1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {4, 5, 6}}};
    for (auto const &a : arr33)
    {
        for (auto const &b : a)
        {
            printf("%i ", b);
        }
        printf("\n");
    }
}
