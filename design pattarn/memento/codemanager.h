#ifndef __CODEMANAGER_H__
#define __CODEMANAGER_H__
#include <vector>
using namespace std;

class Memento;

class CodeManager{
public:
	CodeManager();
	CodeManager(const CodeManager&) = delete;
	CodeManager& operator=(const CodeManager&) = delete;
	~CodeManager();
	void commit(Memento* m);
	// 切换到指定的版本，即回退到指定版本。此处逻辑是返回一个指定的版本的备忘录指针。
	Memento* switchToPointedVersion(int index);
	// 打印历史版本
	void codeLog();
private:
	vector<Memento*> mementoList; //容器储存备忘录对象指针。
	int current_index = 0; //当前版本的下标。
};

#endif