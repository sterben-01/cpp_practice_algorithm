#include <sstream>
#include <string>
#include <iostream>
using namespace std;

class ExpressionVisitor;

struct Expression{ //抽象元素类
    virtual ~Expression() = default;
    virtual void accept(ExpressionVisitor*) = 0;
};

struct DoubleExpression : Expression{ //具体元素1
    double value;
    DoubleExpression(const double value): value{ value } {}

    void accept(ExpressionVisitor*);
};
struct AdditionExpression : Expression{ //具体元素2
    Expression *left, *right;
    AdditionExpression(Expression* const left, Expression* const right): left{ left }, right{ right } {}
    ~AdditionExpression(){
        delete left;
        delete right;
    }
    
    void accept(ExpressionVisitor*);
};



struct ExpressionVisitor{  //抽象访问者
    virtual void visit(Expression*) = 0;
    virtual void visit(DoubleExpression*) = 0;
    virtual void visit(AdditionExpression*) = 0;
};

struct ExpressionPrinter : ExpressionVisitor{  //具体访问者
    void visit(Expression* ptr){
        ptr->accept(this); 
        /*
        第一层多态。调用Expression->accept(ExpressionPrinter*)。这个Expression会根据多态调用。比如是Double还是Addition
        */
    }
    void visit(DoubleExpression* de){
        cout << de->value;
    }
    void visit(AdditionExpression* ae){
        cout << "(";
        visit(ae->left);
        cout << "+";
        visit(ae->right);
        cout << ")";
    }
};

void DoubleExpression::accept(ExpressionVisitor* visitor){
    visitor->visit(this);
    /*
    这是第二层多态调用。根据传入的ExpressionVisitor决定谁调用。此处由于只有一个具体访问者，所以一定是
    ExpressionPrinter->visit(DoubleExpression*)
    */
}
void AdditionExpression::accept(ExpressionVisitor* visitor){
    visitor->visit(this);
    /*
    这是第二层多态调用。根据传入的ExpressionVisitor决定谁调用。此处由于只有一个具体访问者，所以一定是
    ExpressionPrinter->visit(AdditionExpression*)
    */
}
int main(){
    Expression* e = new AdditionExpression{
        new DoubleExpression{ 1 },
        new AdditionExpression{
            new DoubleExpression{ 2 },
            new DoubleExpression{ 3 }
        }
    };
    ExpressionPrinter ep;
    ep.visit(e);

    delete e;
    return 0;
}
