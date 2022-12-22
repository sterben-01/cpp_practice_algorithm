#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>
// namespace area1{
//     template<typename T>
//     class unique_ptr{
//         T* p_ = nullptr;

//         ~unique_ptr(){
//             delete p_;
//         }
//     };
//     template<typename T, typename Deleter>
//     class unique_ptr{
//         T* p_ = nullptr;
//         Deleter d_;
//         ~unique_ptr(){
//             if(p_){
//                 d_(p_);
//             }
//         }
//     };
// }

class myobj{
    public:
    int* ptrs;
    myobj(int val):ptrs(new int(val)){}
    ~myobj(){
        if(ptrs != nullptr){
            delete ptrs;
            ptrs = nullptr;
        }
    }
};

namespace area2{
    template<typename T>
    class default_deleter{ //默认形式的删除器
        public:
        void operator()(T *p) const {
            if(p != nullptr){
                delete p;
                p = nullptr; 
            }
        }
    };

    template<typename T, typename Deleter = default_deleter<T>> //模板表示接受T类型一个接受T类型的删除器
    class unique_ptr{
        public:
        T* p_ = nullptr; //T类型指针
        Deleter d_; //删除器

        explicit unique_ptr(T* ptr): p_(ptr){} //构造函数必须为explicit
        unique_ptr(const unique_ptr& ptr) = delete; //删除拷贝构造
        unique_ptr& operator=(const unique_ptr& ptr) = delete; //删除拷贝赋值

        unique_ptr(unique_ptr&& ptr){ //移动构造函数
            this->p_ = ptr.p_; //注意不是ptr->p_。 ptr是对象不是指针。
            this->d_ = ptr.d_;
            ptr.p_ = nullptr; //切记一定要把ptr也就是要接管的unique ptr的指针置空。否则会double free也达不到独占所有权。
            //也注意这里不能delete ptr。因为资源只有一份。删了就没了。
        }
        unique_ptr& operator=(unique_ptr&& ptr){ //移动赋值
            if(this == &ptr){ //防止自我赋值
                return *this;
            }
            if(this->p_ != nullptr){ //如果自己当前有资源，则释放
                d_(p_); //调用删除器删除T类型指针
                //delete(p_);
                //!注意如果不是调用删除器而是直接用delete的话，则不会调用deleter删除器。这其实是错误行为。必须通过函数调用方式调用删除器。
            }
            this->p_ = ptr.p_; //注意不是ptr->p_。 ptr是对象不是指针。
            this->d_ = ptr.d_;
            ptr.p_ = nullptr; //切记一定要把ptr也就是要接管的unique ptr的指针置空。否则会double free也达不到独占所有权。
        }

        T* operator->() const{ //重载类成员访问操作符。返回对应类型的原始指针。因为我们对裸指针的操作就是 指针->成员。所以我们返回对应原始类型的指针以便调用对应类型的数据。
            return p_;
        }

        T& operator*(){ //解引用自然要返回指向的值。很正常。我们需要返回引用的原因是我们不应将其值拷贝一份再传出。不仅失去了指针的意义而且无法进行如 *ptr = 200 这样的解引用赋值操作。
        //如果返回的是对象，则 *ptr = 200 返回的是临时对象是个右值，右值无法赋值
            return *p_;
        }
        const T& operator*() const{ //有const版本重载的原因是可能有const指针。
            return *p_;
        }
        ~unique_ptr(){
            if(p_ != nullptr){ //析构函数，调用删除器。
                d_(p_);
            }
        }
    };


}

template<typename T>
class my_deleter{ //自己的测试删除器。
    public:
    void operator()(T *p) const {
        if(p != nullptr){
            delete p;
            p = nullptr; 
        }
    }
};
int main(){

    area2::unique_ptr<myobj, my_deleter<myobj>> ptr(new myobj(20));
    //area2::unique_ptr<int, my_deleter<int>> ptr2(new int(30));
    //ptr(std::move(ptr2)); //error
    //area2::unique_ptr<int, my_deleter<int>> ptr(std::move(ptr2));//error
    //area2::unique_ptr<int, my_deleter<int>> ptr2(std::move(ptr));
    // std::cout << *ptr << std::endl;
    // //*ptr = 200300;
    // std::cout << *ptr << std::endl;
    // std::cout << *ptr2->ptr<< std::endl;
    // //*ptr = 200300;
    // std::cout << *ptr2->ptr << std::endl;
    return 0;
}