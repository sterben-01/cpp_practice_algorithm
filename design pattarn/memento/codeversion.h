#ifndef __CODEVERSION_H__
#define __CODEVERSION_H__
#include <iostream>
using namespace std;

class Memento;

class CodeVersion {
public:
	CodeVersion();
	CodeVersion(int iVersion, string iDate, string iLabel);
	// 保存代码
	Memento* save();
	// 回退版本
	void restore(Memento* memento);
	void setVersion(int iVersion);
	int getVersion();
	void setLabel(string iLabel);
	string getLabel();
	void setDate(string iDate);
	string getDate();
private:
	int version; // 代码版本
	string date; // 代码提交日期
	string label;// 代码标签
};

#endif