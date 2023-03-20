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
#include <utility>
#include <future>
#include<functional>
#include <type_traits>
#include <memory>
#include <numeric>
using namespace std;

template<typename... Items>
class typeList{}; //类型列表


template<typename Items> //Item代表了整个typeList。所以此处不需要变参。
class FrontItem{}; //获取第一个元素的主模板。

//因为我们整个塞进去的是typeList。所以我们下面的特化是基于typeList里面的参数的。
template<typename First, typename... Other>
class FrontItem<typeList<First, Other...>>{ //偏特化，把第一个拆开。
    public:
        using type = First; //只保留第一个元素
};

template <typename Items> //此处同FrontItem
class PopFront{}; //移除第一个元素

template<typename First, typename... Other> //此处同FrontItem
class PopFront<typeList<First, Other...>>{
    public:
    using type = typeList<Other...>; //去掉第一个元素，成为新的typelist
};

template<typename Items>
class ListSize{}; //获取类型列表的大小。此处同FrontItem

template<typename... Items> //因为我们不再需要拆开了，所以不需要First模板形参了。
class ListSize<typeList<Items...>>{
    public:
    static inline size_t value = sizeof...(Items);
};


template<typename Items, typename NewItem> //此处同FrontItem, Items是整个typelist, NewItem是新的元素（类型）。
class PushFront{}; //头插

template<typename... Items, typename NewItem> //和pop相反
class PushFront<typeList<Items...>, NewItem>{ //和pop相反
    public:
        using type = typeList<NewItem, Items...>; //直接组合成新的typelist
};




template<typename Items, typename NewItem> //此处同FrontItem, Items是整个typelist, NewItem是新的类型。
class PushBack{}; //尾插

template<typename... Items, typename NewItem> //和头插相同
class PushBack<typeList<Items...>, NewItem>{ //和头插相同
    public:
        using type = typeList<Items..., NewItem>; //直接组合成新的typelist，只是和头插顺序相反。
};


template<typename Items, typename ReplaceItem>
class ReplaceFront{}; //替换第一个元素。

template<typename First, typename... Other ,typename ReplaceItem> //注意这里有三个元素。第一个，剩下的和替换的。
class ReplaceFront<typeList<First, Other...>, ReplaceItem>{
    public:
        using type = typeList<ReplaceItem, Other...>; //直接把第一个换成替换的即可。
};

template<typename Items>
class isEmpty{ //判断是否为空。
    public:
        static inline const bool value = false;
};

template<>
class isEmpty<typeList<>>{ //直接全特化。如果列表为空直接匹配过来。
    public:
        static inline const bool value = true;
};


template<typename Items, unsigned int m_index>
class find_element: public find_element<typename PopFront<Items>::type, m_index-1>{};

template<typename Items>
class find_element<Items, 0>: public FrontItem<Items>{};



using Typelist1 = typeList<int, char, string, double, float>; //类型列表1
using emptylist = typeList<>;

int main(){
    cout << boolalpha;
    cout << typeid(FrontItem<Typelist1>::type).name() << endl;
    cout << ListSize<Typelist1>::value << endl;

    cout << typeid(FrontItem<PopFront<Typelist1>::type>::type).name() << endl;
    cout << ListSize<PopFront<Typelist1>::type>::value<<endl;

    cout << typeid(FrontItem<Typelist1>::type).name() << endl;

    using pushedback = PushBack<Typelist1, int>::type;
    cout << ListSize<pushedback>::value<<endl;

    using pushedfront = PushFront<pushedback, double>::type;
    cout << ListSize<pushedfront>::value<<endl;

    using replaced_front = ReplaceFront<Typelist1, float>::type;
    cout << typeid(FrontItem<replaced_front>::type).name() << endl;


    cout << isEmpty<Typelist1>::value << endl;
    cout << isEmpty<emptylist>::value << endl;


    cout << typeid(find_element<Typelist1, 3>::type).name() << endl;

    // using poped = PopFront<Typelist1>::type;
    // cout << typeid(FrontItem<poped>::type).name() << endl;
    return 0;

}