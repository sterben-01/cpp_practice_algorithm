#include <iostream>
#include <functional>
using namespace std;
class A
{
public:
    virtual std::string clsname() { return "A"; }
    std::string clsname2() { return "A"; }

    void test()
    { std::cout << "A, " << clsname() << ", " << clsname2() << std::endl; }
};

class B : public A
{
public:
    std::string clsname() override { return "B"; }
    virtual std::string clsname2() { return "B"; }

    virtual void test()
    { std::cout << "B, " << clsname() << ", " << clsname2() << std::endl; }
};

class C : public B
{
public:
    std::string clsname() override { return "C"; }
    std::string clsname2() override { return "C"; }

    void test() override
    { std::cout << "C, " << clsname() << ", " << clsname2() << std::endl; }
};

int main()
{
    A a; B b; C c; A d = c;

    b.test();
    c.test();
    d.test();

    ((A&)c).test();
    ((B&)c).test();
    static_cast<A&>(c).test();

    std::bind(&A::test, &b)();
    std::bind(&A::test, &c)();

    std::bind(&B::test, &b)();
    std::bind(&B::test, &c)();

    return 0;
}