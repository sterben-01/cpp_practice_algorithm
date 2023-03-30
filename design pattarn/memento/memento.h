
#ifndef __MEMENTO_H__
#define __MEMENTO_H__
#include <iostream>
using namespace std;


//备忘录类。
/*
在当前业务需求下，我们只需要保存原发器类的版本，日期和标签三个属性
*/


class CodeVersion;

class Memento {
public:
	//Memento() = default;
	Memento(int iVersion, string iDate, string iLabel);
    Memento(CodeVersion* code);
	void setVersion(int iVersion);
	int getVersion();
	void setLabel(string iLabel);
	string getLabel();
	void setDate(string iDate);
	string getDate();
private:
	int version;
	string date;
	string label;
};

#endif