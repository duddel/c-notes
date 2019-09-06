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

#include <cstdio> // printf()
#include "template.h"

int main()
{
   // function template with generic implementation available
   printf("add(2, 3.8f) = %i\n", add(2, 3.8f));
   printf("add<float, float>(2, 3.8f) = %f\n", add<float, float>(2, 3.8f));
   printf("add(2.3f, 3.8f) = %f\n", add(2.3f, 3.8f));

   // class template with selected implementations generated (template_impl.cpp)
   VecA<float, 3> vaf3(1.5f);
   VecA<int, 2> vai2(-4);
// VecA<int, 3> vai3(4); // error: not implemented
   printf("vaf3.sum() = %f\n", vaf3.sum());
   printf("vai2.sum() = %i\n", vai2.sum());

   // class template with partial specialization.
   // VecB<int 1> has member function inv() but not sum()
   VecB<int, 1> vbi1(5);
// printf("vbi1.sum() = %i\n", vbi1.sum());  // error
   printf("vbi1.inv() = %i\n", vbi1.inv());

   return 0;
}
