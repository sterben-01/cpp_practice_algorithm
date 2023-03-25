#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <type_traits>
using namespace std;

struct Resource{ //等同于Subject，抽象主题角色
    virtual void load() = 0;
    virtual ~Resource(){

    }
};


struct Image:Resource{ //等同于Concrete，具体主题角色

    Image(const string& rhs):image_name(rhs){};

    void load(){
        cout <<"image: " << image_name <<" was loaded" << endl;
    }
    string image_name;
};

struct LazyImage: Resource{ //等同于Proxy，代理角色

    LazyImage(const string& rhs):image_name(rhs){};

    void load(){
        if(real_image == nullptr){
            real_image = new Image(image_name); //延迟加载时机。
        }
        real_image->load();
    }
    ~LazyImage(){
        if(real_image != nullptr){
            delete real_image;
        }
        real_image = nullptr;
    }
    private:
        string image_name;
        Image* real_image = nullptr; //内部蕴含一个真实角色
};

/*
我们成功的延迟了资源的加载。这样做有一个前提，也就是在真实角色中，我们模拟的资源加载是在构造函数中进行的，
也就是创建对象即加载。通过代理角色，我们成功的延迟了加载时机。
*/
int main(){
    
    Image my_image1("miku.png");
    cout <<"start loading......" << endl;
    my_image1.load();

    cout <<"-----------------------" << endl;

    LazyImage my_image2("miku.png");
    cout <<"start loading......" << endl;
    my_image2.load();

}