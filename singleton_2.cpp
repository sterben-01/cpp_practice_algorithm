#include<iostream>
using namespace std;





class Student
{
private:
    Student() :age(99) {                                            //私有化构造
        cout << "e_han construct! age=" << age << endl;             
    };

    ~Student() {                                                    //私有化析构
        cout << "e_han destory!" << endl; 
    };

    
    Student(const Student&);                                        //私有拷贝构造
    Student& operator=(const Student&);                             //私有拷贝赋值
    static Student myInstance;                                      //单例对象在这里！


    int age;

public:
    static Student* getInstance()
    {
        return &myInstance;                                         //返回对象的引用
    }
    void printAge()
    {
        cout << this->age << endl;
    }
};

Student Student::myInstance;                                        //为静态对象分配内存


class test{
    public:
    void funcs(){
        int val;
    }
    int ca;
};

int main()
{
    Student* stu_1 = Student::getInstance();
    stu_1->printAge();
    //对象是全局一开始就建立好的，两个函数获取到的是同一个对象
    Student* stu_2 = Student::getInstance();
    stu_2->printAge();
    return 0;
}
