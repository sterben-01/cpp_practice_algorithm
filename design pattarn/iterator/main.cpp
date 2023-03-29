#include <iostream>
#include "iter.cpp"
 
int main()
{
	// 创建电视
	Television* tv = new Television({ "新闻频道", "财经频道", "体育频道", "电影频道", "音乐频道", "农业频道", "四川卫视", "成都卫视" });
	// 创建遥控器
	Iterator* remoteControl = tv->createIterator();
 
	// // 顺序遍历
	printf("顺序遍历:\n");
	remoteControl->first();
	// 遍历电视所有频道
    //由于我们没有写iter++，所以这里比较简陋。转而使用next
	while (remoteControl->hasNext()){
		int cur_channel = remoteControl->currentChannel();
        tv->play(cur_channel);
		remoteControl->next();
	}
 
 
	// 逆序遍历
	printf("逆序遍历:\n");
	remoteControl->last();
	// 遍历电视所有频道
	while (remoteControl->hasPrevious()){
		int cur_channel = remoteControl->currentChannel();
        tv->play(cur_channel);
		remoteControl->previous();
	}
 
	printf("\n\n");
 
	delete tv;
	delete remoteControl;
	
	return 0;
}