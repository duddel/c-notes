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
#include <cstdio> // printf()
#include <memory>

class A
{
public:
    int m_id;

    A(int id) : m_id(id)
    {
        std::printf("A(%i) constructed\n", m_id);
    }

    ~A()
    {
        std::printf("A(%i) deleted\n", m_id);
    }
};

class B
{
public:
    std::unique_ptr<A> m_a1;
    std::unique_ptr<A> m_a2;
    std::unique_ptr<A> m_a3;

    B()
    {
        // no need to delete instances of A manually
        m_a1 = std::unique_ptr<A>(new A(1));
        m_a2 = std::unique_ptr<A>(new A(2));
        m_a3 = std::unique_ptr<A>(new A(3));
    }
};

int main()
{
    {
        // the unique_ptr owns the instance of A and deletes
        // it, if it goes out of scope
        std::unique_ptr<A>(new A(99));
    }

    B b;

    return 0;
}
