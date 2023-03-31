#include "Observer.hpp"
#include "Observable.hpp"
using namespace std;
class Person : public Observable<Person>{ //具体目标类，也就是具体被观察者
  int age{0};
public:
  Person() = default;
  Person(int age) : age(age) {}

  int get_age() const{
    return age;
  }

  void set_age(int age){ //具体目标类既可以实现notify，也可以直接调用基类的update。根据业务代码来书写。
    if (this->age == age){
      return;
    }

    auto old_can_vote = get_can_vote();
    this->age = age;
    notify(*this, "age");

    if (old_can_vote != get_can_vote()){
      notify(*this, "can_vote");
    }
  }

  bool get_can_vote() const {
    return age >= 16;
  }
};


struct ConsolePersonObserver : public Observer<Person>{ //具体观察者。我们可以理解为观察者指的是对某个对象的某个部分或整体（消息）感兴趣的对象。
private:
  void update(Person &source, const std::string &field_name) override{ //这个update的意义在于做出自身的反应。比如在这里我们自身的反应是返回年龄或者是根据年龄判断能否投票
    cout << "Person's " << field_name << " has changed to ";
    if (field_name == "age"){
       cout << source.get_age();
    }
    if (field_name == "can_vote"){
      cout << boolalpha << source.get_can_vote();
    }
    cout << ".\n";
  }
};

struct TrafficAdministration : public Observer<Person>
{
  void update(Person &source, const std::string &field_name) override{ //我们这个自身的反应是根据年龄判断是否可以驾驶汽车。
    if (field_name == "age"){
      if (source.get_age() < 17){
        cout << "Whoa there, you're not old enough to drive!\n";
      }
        
      else{
        cout << "Oh, ok, we no longer care!\n";
        source.unsubscribe(*this);
      }
    }
  }
};

int main(int ac, char* av[]){
  Person p;
  TrafficAdministration ta;
  p.subscribe(ta);

  p.set_age(15);
  p.set_age(16);
  p.set_age(17);
  

  return 0;
}