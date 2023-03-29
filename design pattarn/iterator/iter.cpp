#include "aggregate.h"
#include <vector>
#include <iostream>
using namespace std;

// 抽象迭代器
class Iterator
{
public:
	Iterator(){}
	virtual ~Iterator(){}
	// 声明抽象遍历方法
	virtual void first() = 0;
	virtual void last() = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual bool hasNext() = 0;
	virtual bool hasPrevious() = 0;
	virtual int currentChannel() = 0;
private:

};

// 遥控器：具体迭代器
class RemoteControl :public Iterator
{
public:
	RemoteControl() = default;
	RemoteControl(Television* rtv):tv(rtv), index(-1), totalNum(tv->getTotalChannelNum()){
		cout <<"cal" << endl;
	}
	// 实现各个遍历方法
	void first(){
		index = 0;
	}
	void last(){
		index = totalNum - 1;
	}
	void next(){
		index++;
	}
	void previous(){
		index--;
	}
	bool hasNext(){
		return !(index == totalNum);
	}
	bool hasPrevious(){
		return !(index == -1);
	}
	int currentChannel(){
		return index;
	}
private:
	Television* tv; // 电视
	int index; 	// 下标
	int totalNum; 	// 总的频道数目
};

