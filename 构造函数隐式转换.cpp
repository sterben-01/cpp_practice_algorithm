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
using namespace std;


class tmp{
    public:
    string _text;
    tmp(string c): _text(c) {}

};
class test{
    public:
    string _text;
    test(string a): _text(a){}
    explicit test(tmp s): _text(s._text){} //test类的构造函数接受tmp类型的对象。
};

class twonumber{
    public:
    test ret(){
        test(tmp("cde"));
        return(tmp("abc")); //此处返回的对象是一个tmp，但是函数头的返回类型却是test。因为这里使用了构造函数的隐式转换。也就是test类的构造函数接受tmp类型的对象
        //!由于return语句内是隐式转换，所以对应的构造函数如果有explicit关键字则无法进行隐式转换。
        /*
        注意！由四种情况会发生隐式转换：
        1. 混合类型的算数运算表达式。
        int a = 3;
        double b = 4.5;
        a + b; // a将会被自动转换为double类型，转换的结果和b进行加法操作
        2. 不同类型的赋值操作。
        int a = true ; ( bool 类型被转换为 int 类型)
        int * ptr = null;（null被转换为 int *类型）
        3. 函数参数传值
        void func( double a);
        func(1); // 1被隐式的转换为double类型1.0
        4. 函数返回值。（此处例子）
        double add( int a, int b)
        {
            return a + b;
        } //运算的结果会被隐式的转换为double类型返回
        */
    }

};

int main(){
    twonumber ttt;
    test rrr = ttt.ret();
    cout << rrr._text << endl;
    return 0;
}

/*
.
└── douyin/
    ├── config/                             //! 配置文件
    │   ├── config.go
    │   └── config.yaml
    ├── controller/                         //! 控制层
    │   ├── commonctl/                      #整体控制层
    │   │   ├── encrypt.go
    │   │   ├── response.go
    │   │   └── token.go
    │   ├── userctl/                        #用户操作控制层
    │   │   ├── follow.go
    │   │   ├── follow_list.go
    │   │   ├── follower_list.go
    │   │   ├── login.go
    │   │   ├── register.go
    │   │   └── user_page.go
    │   └── videoctl/                       #视频操作控制层
    │       ├── comment.go
    │       ├── commentlist.go
    │       ├── feed.go
    │       ├── get_cover.go
    │       ├── like.go
    │       ├── likelist.go
    │       ├── oss.go
    │       ├── publish.go
    │       └── publish_list.go
    ├── repository/                         #仓储层
    │   ├── comment.go
    │   ├── follow.go
    │   ├── init.go
    │   ├── like.go
    │   ├── user.go
    │   └── video.go
    ├── router/                             #路由加载模块
    │   └── addRouter.go
    ├── service/                            #服务层
    │   ├── usersvc/                        #用户服务层
    │   │   ├── follow.go
    │   │   ├── follow_list.go
    │   │   ├── follower_list.go
    │   │   ├── login.go
    │   │   ├── register.go
    │   │   └── user_info.go
    │   └── videosvc/                       #视频服务层
    │       ├── comment.go
    │       ├── commentlist.go
    │       ├── feed.go
    │       ├── like.go
    │       ├── likelist.go
    │       ├── publish.go
    │       └── publishlist.go
    ├── .gitignore
    ├── main.go
    └── README.md
*/