#include <iostream>
#include <cstring>
using namespace std;
class ClassTest
{
public:
    ClassTest()
    {
        c[0] = '\0';
        cout << "ClassTest()" << endl;
    }
    ClassTest& operator=(const ClassTest &ct)
    {
        strcpy(c, ct.c);
        cout << "ClassTest& operator=(const ClassTest &ct)" << endl;
        return *this;
    }
    ClassTest(ClassTest&& ct)
    {
        cout << "ClassTest(ClassTest&& ct)" << endl;
    }
    ClassTest & operator=(ClassTest&& ct)
    {
        strcpy(c, ct.c);
        cout << "ClassTest & operator=(ClassTest&& ct)" << endl;
        return *this;
    }
    ClassTest(const char *pc)
    {
        strcpy(c, pc);
        cout << "ClassTest (const char *pc)" << endl;
    }
    //private:
    ClassTest(const ClassTest& ct)
    {
        strcpy(c, ct.c);
        cout << "ClassTest(const ClassTest& ct)" << endl;
    }
    virtual  int ff()
    {
        return 1;
    }
private:
    char c[256];
};
ClassTest f1()
{
    ClassTest c;
    return c;
}
void f2(ClassTest ct)
{
    ;
}
int main()
{
    ClassTest ct1("ab");//直接初始化
    ClassTest ct2 = "ab";//复制初始化
    ClassTest ct3 = ct1;//复制初始化
    ClassTest ct4(ct1);//直接初始化
    ClassTest ct5 = ClassTest("ab");//复制初始化
    ClassTest ct6 = f1();
    f1();
    f2(ct1);
    return 0;
}