#include<iostream>
using namespace std;
class Student
{
private:
    Student() :age(99) { 									//私有构造
        cout << "e_han construct! age=" << age << endl; 
    };
    ~Student() { 											//私有析构
        cout << "e_han destory!" << endl; 
    };
    int age;
    Student(const Student&);								//私有拷贝构造
    Student& operator=(const Student&);						//私有拷贝赋值

public:
    static Student& getInstance()				//注意是返回单例实例对象的引用
    {   
        static Student myInstance;              //注意这里，这里是局部静态变量。静态变量的生存周期是从声明起至程序结束。 		
        return myInstance;					//返回实例对象
    }
    void printAge()
    {
        cout << this->age << endl;
    }
};
int main()
{
    Student& stu_1 = Student::getInstance();	//注意这里要用引用去接。
    stu_1.printAge();
    Student& stu_2 = Student::getInstance();
    stu_2.printAge();
    return 0;
}