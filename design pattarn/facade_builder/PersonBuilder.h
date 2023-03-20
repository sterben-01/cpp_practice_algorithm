#pragma once
#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase //理解为抽象建造者
{
protected:
  Person& person;
  /*
  这个持有引用非常有意思。首先我们发现这个唯一的构造函数是protected，所以除了子类其他人不能调用。
  其次呢，我们持有一个person对象的引用的原因是我们的三个具体建造者希望共享同一个person对象，最佳的方式就是父类持有一个person引用。
  一开始，person的创建函数会返回一个personbuilder对象。personbuilder负责初始化一个person对象。然后在构造中调用父类的构造函数把参数传给父类。
  然后根据链式调用，在base类中，lives返回PersonAddressBuilder对象，works返回PersonJobBuilder对象。二者都是通过base类的person引用初始化的。
  同时，为了满足链式调用，会返回一个对应建造者类的引用。
  当切换建造者类的时候，由于无论是AddressBuilder还是JobBuilder类，都是继承自base基类。所以可以天然的调用base基类的函数lives或works进行切换。
  */
  explicit PersonBuilderBase(Person& person): person(person){}
public:
  operator Person() const{
    /*
    这个用户定义转换很有趣。因为我们最后一顿链式调用返回的对象类型一定要么是JobBuilder，要么是AddressBuilder。反正会是base的子类或base。但是person和base没有任何联系。
    我们等号左侧是person对象，右侧是一个builder对象。自然无法赋值。所以说要有一个类型转换函数。
    这个类型转换的唯一作用是把我们builder创建的base对象在整个流程完毕后，移入等号左侧的person对象中。拷贝初始化然后调用移动构造。
    */
    std::cout <<"convert called" << std::endl;
    return std::move(person);
  }

  // builder facets

  PersonAddressBuilder lives() const;
  PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase //理解为具体建造者
{
  Person p;
public:
  PersonBuilder(): PersonBuilderBase{p}
  {
  }

};