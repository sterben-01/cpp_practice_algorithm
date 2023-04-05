#include <string>
#include <iostream>
#include <typeinfo>
#include <memory>
#include <unordered_map>
#include <functional>
#include <cxxabi.h>

namespace neb{
    class Actor{ //*理解为反射基类 reflectobject
    public:
        Actor(){std::cout << "Actor construct" << std::endl;}
        virtual ~Actor(){};
        virtual void Say()
        {
            std::cout << "Actor" << std::endl;
        }
    };

    template<typename ...Targs>
    class ActorFactory{  //*理解为反射器类。此处是单例模式
    public:
        //typedef Actor* (*ActorCreateFunction)();
        //std::function< Actor*(Targs...args) > pp;

        static ActorFactory* Instance(){  //! 线程不安全的单例模式。获取反射器指针。
            std::cout << "static ActorFactory* Instance()" << std::endl;
            if (nullptr == m_pActorFactory){
                std::cout << "static ActorFactory NEW CREATE" << std::endl;
                m_pActorFactory = new ActorFactory();
            }
            return(m_pActorFactory);
        }

        virtual ~ActorFactory(){};

        //Lambda: static std::string ReadTypeName(const char * name)

        //bool Regist(const std::string& strTypeName, ActorCreateFunction pFunc)
        //bool Regist(const std::string& strTypeName, std::function<Actor*()> pFunc)
        /*
        
        &将“实例创建方法（对象工厂的CreateObject方法）”注册到ActorFactory，注册的同时赋予这个方法一个名字“类名”，后续可以通过“类名”获得该类的“实例创建方法”。
        &这个实例创建方法实质上是个函数指针，在C++11里std::function的可读性比函数指针更好，所以用了std::function。
        */
        bool Regist(const std::string& strTypeName, std::function<Actor*(Targs&&... args)> pFunc){
            std::cout << "bool ActorFactory::Regist(const std::string& strTypeName, std::function<Actor*(Targs... args)> pFunc)" << std::endl;
            if (nullptr == pFunc){
                return(false);
            }
            std::string strRealTypeName = strTypeName;
            //[&strTypeName, &strRealTypeName]{int iPos = strTypeName.rfind(' '); strRealTypeName = std::move(strTypeName.substr(iPos+1, strTypeName.length() - (iPos + 1)));};

            bool bReg = m_mapCreateFunction.insert(std::make_pair(strRealTypeName, pFunc)).second; // 创建键值对
            std::cout << "m_mapCreateFunction.size() =" << m_mapCreateFunction.size() << std::endl;
            return(bReg);
        }

        //& 传入“类名”和参数创建类实例，方法内部通过“类名”从m_mapCreateFunction获得了对应的“实例创建方法（DynamicCreator的CreateObject方法）”完成实例创建操作。
        Actor* Create(const std::string& strTypeName, Targs&&... args){
            std::cout << "Actor* ActorFactory::Create(const std::string& strTypeName, Targs... args)" << std::endl;
            auto iter = m_mapCreateFunction.find(strTypeName);
            if (iter == m_mapCreateFunction.end()){
                return(nullptr);
            }
            else{
                //return(iter->second());
                return(iter->second(std::forward<Targs>(args)...)); //把参数完美转发至实例创建方法。
            }
        }

    private:
        ActorFactory(){std::cout << "ActorFactory construct" << std::endl;}; //私有构造，经典的单例模式
        static ActorFactory<Targs...>* m_pActorFactory;   //静态的单例的本类指针
        std::unordered_map<std::string, std::function<Actor*(Targs&&...)> > m_mapCreateFunction; //存贮映射的数据结构。第二个std::function对象统一存储返回类型是Actor*入参可变的函数。
    };

    template<typename ...Targs>
    ActorFactory<Targs...>* ActorFactory<Targs...>::m_pActorFactory = nullptr; //静态的单例的本类指针的类外定义

    template<typename T, typename ...Targs>
    class DynamicCreator{  //*理解为对象工厂
    /*
    我们写自己的业务类的时候，不仅要继承自反射基类，也要继承自这个类。
    继承自这个类的第一个参数就是我们的类名。会通过mangled方法获取到这个字符串
    然后把这个字符串和这个类的CreateObject函数放进去
    */
    public:
        struct Register{
            Register(){
                std::cout << "DynamicCreator.Register construct" << std::endl;
                std::puts(__PRETTY_FUNCTION__);
                char* szDemangleName = nullptr;
                std::string strTypeName; //这个就是类名
                #ifdef __GNUC__
                    szDemangleName = abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, nullptr);
                #else
                //in this format?:     szDemangleName =  typeid(T).name();
                    szDemangleName = abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, nullptr);
                #endif
                if (nullptr != szDemangleName){
                    strTypeName = szDemangleName;
                    free(szDemangleName);
                }
                std::cout << strTypeName << std::endl;
                ActorFactory<Targs...>::Instance()->Regist(strTypeName, CreateObject); //通过反射器类实例把类名和创建函数放进去。
            }
            inline void do_nothing()const { }; //!注意这个do_nothing。
        };
        DynamicCreator(){
            std::puts(__PRETTY_FUNCTION__);
            std::cout << "DynamicCreator construct" << std::endl;
            m_oRegister.do_nothing(); //!这里的目的是使用一次我们嵌套类的static对象。这样的话编译器不会优化掉嵌套类静态对象的构造。尤其是分离编译的时候，可能会发生链接错误。
        }
        virtual ~DynamicCreator(){m_oRegister.do_nothing();}; //!这里我就不知道为什么了

        static T* CreateObject(Targs&&... args){ //这个实例创建函数很有意思。别看它返回的是T*，但是由于我们所有的业务代码具体类都需要继承自反射基类。所以说T*是子类指针，而反射器存储的是Actor*父类指针。很自然的多态存储。
            std::cout << "static Actor* DynamicCreator::CreateObject(Targs... args)" << std::endl;
            return new T(std::forward<Targs>(args)...); //一旦调用这个函数，就执行这个new。把传进来的参数再次完美转发至对象类的构造函数。
        }

        virtual void Say(){
            std::cout << "DynamicCreator say" << std::endl;
        }
        static Register m_oRegister; //这里必须要是静态的。
    };

    template<typename T, typename ...Targs>
    typename DynamicCreator<T, Targs...>::Register DynamicCreator<T, Targs...>::m_oRegister; //成员static变量的类外定义并初始化。


    //下面开始是业务类。第一个是继承自反射基类，然后继承自对象工厂类。对象工厂类第一个模板参数是本类类型，然后依次是构造函数参数类型。
    class Cmd: public Actor, public DynamicCreator<Cmd>{
    public:
        Cmd(){std::cout << "Create Cmd " << std::endl;}
        virtual void Say(){
            std::cout << "I am Cmd" << std::endl;
        }
    };

    class Step: public Actor, DynamicCreator<Step, std::string, int>{
    public:
        Step(const std::string& strType, int iSeq){std::cout << "Create Step " << strType << " with seq " << iSeq << std::endl;}
        virtual void Say(){
            std::cout << "I am Step" << std::endl;
        }
    };

    struct miku:public Actor, DynamicCreator<miku, int, int>{
        miku(int x, int y){
            std::cout <<"miku" << x << y << std::endl;
        }
    };

    class Worker{
    public:
        template<typename ...Targs>
        Actor* CreateActor(const std::string& strTypeName, Targs&&... args){
            Actor* p = ActorFactory<Targs...>::Instance()->Create(strTypeName, std::forward<Targs>(args)...);
            return(p);
        }
    };

}

int main()
{
    //Actor* p1 = ActorFactory<std::string, int>::Instance()->Create(std::string("Cmd"), std::string("neb::Cmd"), 1001);
    //Actor* p3 = ActorFactory<>::Instance()->Create(std::string("Cmd"));
    // neb::Worker W;
    // std::cout << "----------------------------------------------------------------------" << std::endl;
    // neb::Actor* p1 = W.CreateActor(std::string("neb::Cmd"));
    // p1->Say();
    // //std::cout << abi::__cxa_demangle(typeid(Worker).name(), nullptr, nullptr, nullptr) << std::endl;
    // std::cout << "----------------------------------------------------------------------" << std::endl;
    // neb::Actor* p2 = W.CreateActor(std::string("neb::Step"), std::string("neb::Step"), 1002);
    // p2->Say();

    // std::cout << "----------------------------------------------------------------------" << std::endl;
    // neb::Actor* p3 = W.CreateActor(std::string("neb::miku"),2,3);
    // p3->Say();
    return(0);
}