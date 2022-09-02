#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <sstream>
#include <list>
#include <algorithm>
#include<functional>
#include <type_traits>
#include <memory>
using namespace std;

template<typename T>

class shptr{
    public:
        explicit shptr(T* obj):data(obj), count(new int (1)){}



        shptr(const shptr& rhs):data(rhs.data), count(rhs.count){ //拷贝构造。传入的是智能指针的话不需要新建引用计数（控制块）。直接加1即可。切记这里复制一定要是浅拷贝，因为共用控制块和资源。
            *count = *count + 1;
        }

        shptr& operator=(const T& rhs){     //拷贝赋值
            if(&rhs == this){       //判断是否是自我赋值
                return *this;
            }

            this->*count -= 1;
            if(this->*count <= 0){ //自身原值如果减1后引用计数为0，释放自身资源
                delete data;
                delete count;
            }
            //此处不可写else。因为我们是先清空自己，再把rhs数据放到我们身上。
            this->data = rhs.data;      
            this->count = rhs.count;
            *count = *count + 1;        //引用计数+1
        }

        T& operator*() const{ //解引用自然要返回指向的值。很正常。我们需要返回引用的原因是我们不应将其值拷贝一份再传出。失去了指针的意义。
            return *data;
        }

        T* operator->()const{   //成员访问运算符。返回原始指针。因为我们对裸指针的操作就是 指针->成员。所以我们返回对应原始类型的指针以便调用对应类型的数据。
            return data;
        }



        ~shptr(){
            *count = *count - 1; //引用计数-1
            if(*count <= 0){     //如果引用计数为0了，删除资源。
                delete data;
                delete count;
            }
        }




        int use_count(){
            return *count;
        }

    private:
        T* data;
        int* count;         //简化的控制块。控制块需要单独开辟。

};

int main(){
    shptr<int> p1(new int(10));
    cout << p1.use_count() << endl;
    shptr<int> p2 = p1;
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
    shptr<int> p3(p1);
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
    cout << p3.use_count() << endl;
    cout << *p1 << endl;
    return 0;
}