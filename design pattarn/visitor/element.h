#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include <string>
#include "visitor.h"
using namespace std;
struct Element{ //抽象元素类
    int number = 0;
    int price = 0;
    string name;
    Element() = default;
    Element(int x, int y, const string& n):number(x), price(y),name(n){};
    virtual void accept(Visitor*) = 0;
    virtual ~Element(){};
};


struct Apple : Element{ //具体访问类1
    Apple() = default;
    using Element::Element;
    void accept(Visitor*);
};

struct Badge : Element{ //具体访问类2
    Badge() = default;
    using Element::Element;
    void accept(Visitor*);
};



#endif