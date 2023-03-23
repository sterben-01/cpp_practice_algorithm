#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <type_traits>
using namespace std;

//此处是透明组合模式


//抽象构件类
struct Component{
	Component() = default;
	virtual void add(Component*) = 0;
	virtual void remove(Component*) = 0;
	virtual void operation() = 0;
	virtual string getname() = 0;
	virtual ~Component(){}
};

//叶子构件类1
//由于我们是透明组合模式，所以叶子构件类的添加和移除操作应不做任何事情。因为叶子构件类本身不含有叶子结点。
struct Circle: Component{
	Circle() = default;
	Circle(const string& rhs):name(rhs){}
	void add(Component*){
		cout <<"invalid" << endl;   //无作用
	}
	void remove(Component*){ 
		cout << "invalid" << endl;  //无作用
	}
	void operation(){ //具体动作
		cout <<"draw circle: " << name <<endl;
	}
	string getname(){
		return name;
	}
	string name; //具体成员变量。
};

//叶子构件类2
struct Square: Component{
	Square() = default;
	Square(const string& rhs):name(rhs){}
	void add(Component*){
		cout <<"invalid" << endl;
	}
	void remove(Component*){
		cout << "invalid" << endl;
	}
	void operation(){ //具体动作
		cout <<"draw square" << name <<endl;
	}
	string getname(){
		return name;
	}
	string name; //具体成员变量。
};

//容器构件类
struct Composite: Component{
	Composite() = default;
	Composite(const string& rhs):name(rhs){}
	void add(Component* ptr){//添加节点。
		my_container.push_back(ptr);
	}
	void remove(Component* ptr){ //移除特定元素。此处逻辑是根据名字
		for(int i = 0; i < my_container.size(); i++){
			if(my_container[i]->getname() == ptr->getname()){
				my_container.erase(my_container.begin() + i);
				break;
			}
		}
	}
	void operation(){ //具体动作。多态地调用容器构件或叶子构件的具体动作。以实现嵌套调用。
		cout <<"in composite: " << name << endl;
		for(auto& item: my_container){
			item->operation();
		}
	}
	string getname(){
		return name;
	}

    vector<Component*> my_container; //容器构建类含有一个存有抽象构建类对象或指针的容器。
	string name; //因为容器构件可以嵌套容器构件，所以容器构件也应该有名字。
};

int main(){

	Component* circle1 = new Circle("circle1");
	Component* circle2 = new Circle("circle2");

	Component* composite1 = new Composite("composite1");
	Component* composite2 = new Composite("composite2");
	composite1->add(circle1);
	composite1->add(circle2);
	

	Component* square1 = new Square("square1");
	Component* square2 = new Square("square2");

	composite2->add(composite1);
	composite2->add(square1);
	composite2->add(square2);
	composite2->operation();
    //截止到此处，容器2包含容器1和两个方形，容器1包含两个圆形，并执行具体动作

    cout <<"---" << endl;
    composite2->remove(composite1); //移除容器1，所以容器1的两个圆形也会被移除
    composite2->operation();//执行具体动作
    


	delete circle1;
	delete circle2;
	delete composite1;
	delete composite2;
	delete square1;
	delete square2;

    /*
    in composite: composite2
    in composite: composite1
    draw circle: circle1
    draw circle: circle2
    draw squaresquare1
    draw squaresquare2
    ---
    in composite: composite2
    draw squaresquare1
    draw squaresquare2
    */
	return 0;
}