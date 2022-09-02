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
#include <mutex>
using namespace std;
//text 单例，懒汉 双检锁。
mutex my_mutex;
class Student{
	private:
		Student() :age(99) {									//私有化构造
			cout << "lan_han construct!this age=" << age << endl;
		};

		~Student() {											//私有化析构
			cout << "lan_han destory!" << endl; 
		};

		Student(const Student&);								//私有化拷贝构造

		Student& operator=(const Student&);						//私有化拷贝赋值

		int age;

		static Student* myInstance;								// 这里是对象指针，不是一个实例化对象了。因为是懒汉式，只有用到的时候才会实例化。

	public:
		static Student* getInstance()							//静态函数，返回一个单例实例的指针。
        {	
            if (myInstance == nullptr)							//先判断是否为空
            {
                my_mutex.lock();								//确定空后再加锁
                if(myInstance == nullptr){						//再次判断是否为空
                    myInstance = new Student();					//实例化
                }	
                my_mutex.unlock();								//解锁
            }

            return myInstance;//返回对象指针
        }
		void printAge()
		{
			cout << this->age << endl;
		}
	private:
		// 定义一个内部类
		class CGarbo {
		public:
			CGarbo() {};
			// 定义一个内部类的静态对象
			static CGarbo m_garbo;													

			~CGarbo()//对象程序结束析构时对主类指针释放内存
			{
				if (myInstance != nullptr)
				{
					delete myInstance;
					myInstance = nullptr;
				}
			}
		};
};
//记得要初始化静态对象，里面只是定义了他，没有分配内存空间
Student* Student::myInstance = nullptr;						//为静态对象分配内存
Student::CGarbo Student::CGarbo::m_garbo;					//为静态对象分配内存
int main()
{
	Student* stu_1 = Student::getInstance();
	stu_1->printAge();

	Student* stu_2 = Student::getInstance();
	stu_2->printAge();

	return 0;
}
