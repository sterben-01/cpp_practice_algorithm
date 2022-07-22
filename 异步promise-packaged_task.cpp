#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>
 

//? 使用packaged_task进行异步
int accumulate(std::vector<int>::iterator first,
                std::vector<int>::iterator last)
{
    int sum = std::accumulate(first, last, 0);
    return sum;
}
 
int main()
{
    // 演示用 packaged_task 在线程间传递结果。
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6 };
    std::packaged_task<int(std::vector<int>::iterator,std::vector<int>::iterator)> accumulate_task(accumulate);
    std::future<int> accumulate_future = accumulate_task.get_future();
    std::thread work_thread(std::move(accumulate_task), numbers.begin(), numbers.end());

    //%std::thread work_thread(std::ref(accumulate_task), numbers.begin(), numbers.end());
    /*
    !可以用ref但是不推荐。因为如果你不转移所有权，万一你多个线程并发访问了promise，可能会有问题，
    !而且这也不符合设计，一般来说只应该让一个线程持有promise
    @ 使用move的主要原因还有一个就是按值传递函数参数会调用拷贝构造。packaged_task禁用了拷贝构造，要么传引用要么换成右值引用转移所有权。
    */

    //&thread构造函数模板是T&& 这个是万能引用。若采用右值来初始化万能引用，就会得到一个右值引用，如果采用左值来初始化，则会得到一个左值引用。

    accumulate_future.wait();  //等待结果
    std::cout << "result=" << accumulate_future.get() << '\n';
    work_thread.join();  //阻塞等待线程执行完成
 
    getchar();
    return 0;
}



//?使用promise进行异步
void accumulate2(std::vector<int>::iterator first,
                std::vector<int>::iterator last,
                std::promise<int> accumulate_promise)
{
    int sum = std::accumulate(first, last, 0);
    accumulate_promise.set_value(sum);  // 将结果存入，并让共享状态变为就绪以提醒future
}
 
int main()
{
    // 演示用 promise<int> 在线程间传递结果。
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6 };
    std::promise<int> accumulate_promise;
    std::future<int> accumulate_future = accumulate_promise.get_future();
    std::thread work_thread(accumulate2, numbers.begin(), numbers.end(),
                            std::move(accumulate_promise));
    //!这里也可以用ref。但是我们accumulate2的函数头要了个值。promise又禁用了拷贝构造所以这里目前只可以move。如果accumulate2函数头改为&就可以用ref
    accumulate_future.wait();  //等待结果
    std::cout << "result=" << accumulate_future.get() << '\n';
    work_thread.join();  //阻塞等待线程执行完成
 
    getchar();
    return 0;
}