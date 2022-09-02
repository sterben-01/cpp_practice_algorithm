#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;


// class Singleton{

//     private:
//         Singleton();                            //私有化构造
//         Singleton(const Singleton&){}           //私有化拷贝构造
//         Singleton& operator=(const Singleton&){} //私有化拷贝赋值

// };
class Student
{
private:
	Student():age(99){ cout << "lan_han construct!this age="<<age << endl; };
    ~Student(){ cout << "lan_han destory!" << endl; };
	Student(const Student &);//设置拷贝构造和操作符=重载防止对象拷贝
	Student& operator=(const Student &);
    int age;
 
	static Student *myInstance; // 这里是对象指针，不是一个实例化对象了
public:
	static Student* getInstance()
	{		
		if(myInstance==nullptr)
        {
            myInstance=new Student();
        } 
        return myInstance;//返回对象指针
	}
    void printAge()
    {
        cout<<this->age<<endl;
    }
private:
	// 定义一个内部类
	class CGarbo{
	public:
		CGarbo(){};
		// 定义一个内部类的静态对象
		static CGarbo m_garbo;
		
		~CGarbo()//对象程序结束析构时对主类指针释放内存
		{
			if (nullptr != myInstance)
			{
				delete myInstance;
				myInstance = nullptr;
			}
		}
	};
};
//记得要初始化静态对象，里面只是定义了他，没有分配内存空间
Student* Student::myInstance=nullptr;
Student::CGarbo Student::CGarbo::m_garbo;
//  int main()
//  {
//      Student *stu_1=Student::getInstance();
//     stu_1->printAge();

//     Student *stu_2=Student::getInstance();
//     stu_2->printAge();

//      return 0;
//  }
int main()
{	
	double my = 4.4444;
	double my1 = 3.333;
	int&& myref = my;
	double& myref1 = my1;
	cout << myref << endl;
	my = 6.666;
	cout << myref << endl;
	cout << myref1 << endl;
	my1 = 6.666;
	cout << myref1 << endl;
    return 0;
}