/*
this file is part of c-notes
https://github.com/duddel/c-notes

C++ - struct vs. class
*/

struct A
{
    // public by default
    int i;
    A(int _i) : i(_i) {}
};

class B
{
public:
    int i;
    B(int _i) : i(_i) {}
};

int main()
{
    // struct A and class B are equivalent
    A a(1);
    B b(1);

    return 0;
}
