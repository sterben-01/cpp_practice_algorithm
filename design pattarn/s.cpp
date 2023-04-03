#include <sstream>
#include <string>
#include <iostream>
using namespace std;
class ExpressionPrinter;
struct Expression{ //抽象元素类
    virtual ~Expression() = default;
    virtual void print(ExpressionPrinter*) = 0;
};

struct DoubleExpression : Expression{ //具体元素1
    double value;
    DoubleExpression( double value): value{ value } {}

    void print( ExpressionPrinter*);
};

struct AdditionExpression : Expression{ //具体元素2
    Expression* left, * right;
    AdditionExpression(Expression*  left, Expression*  right): left{ left }, right{ right } {}
    ~AdditionExpression(){
        delete left;
        delete right;
    }

    void print(ExpressionPrinter*);
};

struct ExpressionPrinter{ //具体访问者
    void print(Expression* ptr)  {
        ptr->print(this);
    }
    void print(DoubleExpression* de) {
        cout << de->value;
    }
    void print(AdditionExpression* ae) {
        cout << "(";
        print(ae->left);
        cout << "+";
        print(ae->right);

        cout << ")";
    }
};



void DoubleExpression::print(ExpressionPrinter* ptr){
    ptr->print(this);
}
void AdditionExpression::print( ExpressionPrinter* ptr){
    ptr->print(this);
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
    ep.print(e);

    delete e;
    return 0;
}