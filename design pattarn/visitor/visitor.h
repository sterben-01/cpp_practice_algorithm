#ifndef __VISITOR_H__
#define __VISITOR_H__

class Element;
class Apple;
class Badge;

struct Visitor{ //抽象访问者
    Visitor() = default;
    virtual ~Visitor(){};
    virtual void visit(Apple*) = 0;
    virtual void visit(Badge*) = 0;
};


struct People : Visitor{ //具体访问者1
    People() = default;
    virtual void visit(Apple*);
    virtual void visit(Badge*);   
};

struct Boss : Visitor{ //具体访问者2
    Boss() = default;
    virtual void visit(Apple*);
    virtual void visit(Badge*);   
};





#endif