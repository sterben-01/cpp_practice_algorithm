#ifndef __AGGREGATE_H__
#define __AGGREGATE_H__
 
#include <vector>
#include <string>
using namespace std;
 
// 前向声明，因为具体聚合类包含一个迭代器类的指针。
class Iterator;

// 抽象聚合类 Aggregate
class Aggregate
{
public:
	Aggregate(){}
	virtual ~Aggregate(){}
	virtual Iterator* createIterator() = 0; //创建迭代器的接口
};
 
// 具体聚合类 ConcreteAggregate
class Television :public Aggregate
{
public:
	Television();
	Television(const vector<string>& iChannelList);
	Iterator* createIterator(); // 实现创建迭代器
	int getTotalChannelNum(); // 获取总的频道数目
	void play(int i);
private:
	vector<std::string> channelList; //这个就是我们迭代器类要遍历的对象。
};
 
#endif //__AGGREGATE_H__