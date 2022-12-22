#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include<memory>
#include <map>
#include <unordered_map>
#include <future>
#include <atomic>
#include <unordered_set>
using namespace std;
class Student
{
    public:
    int age;
private:
    Student() :age(99) { 									//私有构造
        cout << "e_han construct! age=" << age << endl; 
    };
    ~Student() { 											//私有析构
        cout << "e_han destory!" << endl; 
    };
    
    Student(const Student&);								//私有拷贝构造
    Student& operator=(const Student&);						//私有拷贝赋值

public:
    static Student& getInstance()				//注意是返回单例实例对象的引用
    {   
        static Student myInstance;              //注意这里，这里是局部静态变量而不是类成员变量。局部静态变量的生存周期是从声明起至程序结束。 		
        return myInstance;					//返回实例对象
    }
    void printAge()
    {
        cout << this->age << endl;
    }
};


void process(vector<int>& nums){
    int left = 0;
    int right = nums.size()-1;
    while(left < right){
        while(nums[left] == 0){
            left++;
        }
        while(nums[right] == 1){
            right--;
        }
        nums[left] = 0;
        nums[right] = 1;
        left++;
        right--;
    }
}

class person{
    public:
        int id = 20;
        static int info;
};
int person::info = 10;

// int main()
// {
//     person human;
//     person* human_ptr = new person();
//     int person::*nonstatic_ptr = &person::id;
//     cout << human.*nonstatic_ptr << endl; //对象调用
//     cout << human_ptr->*nonstatic_ptr << endl; //指针调用

//     int* static_ptr = &person::info;
//     cout << *static_ptr << endl; //指针访问
//     cout << person::info << endl;//直接通过作用域运算符访问类静态成员变量。
//     return 0;
// }
template<typename T> //要有单参打印的重载。不然会无限调用。
void print(T t){
    cout << t << endl;
}


template<typename... Args>
void print(Args... args){
    (print(args), ...); //这里外部一定要加括号。注意语法
}

class testnum{
    public:
        testnum(){
            //val = 8964;
        }
        int val = 200;
};
int main() 
{
    
    //print(1, 1000, "b23", 1.123, "HahaahaH", 42);
    // set<int>a {1,2,3,4,5,6,7};
    // set<int>::iterator myiter = a.begin();
    // myiter++;
    // myiter--;
    int arr[10]{};

    for(int i = 0; i < 10; i++){
        cout << arr[i] << endl;
    }
    // myiter = a.begin()+3;
    // cout << *myiter << endl;
    return 0;
}