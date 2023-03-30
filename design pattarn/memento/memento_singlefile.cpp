#include <iostream>
#include <vector>
using namespace std;


//备忘录类。
/*
在当前业务需求下，我们只需要保存原发器类的版本，日期和标签三个属性
*/

class Memento {
public:
	Memento() = default;
	Memento(int iVersion, string iDate, string iLabel) :version(iVersion), date(iDate), label(iLabel) {}
	void setVersion(int iVersion) {
		version = iVersion;
	}
	int getVersion() {
		return version;
	}
	void setLabel(string iLabel) {
		label = iLabel;
	}
	string getLabel() {
		return label;
	}
	void setDate(string iDate) {
		date = iDate;
	}
	string getDate() {
		return date;
	}
private:
	int version;
	string date;
	string label;
};

// 原发器类
/*
原发器类其实就是我们的业务代码。我们需要记录状态的类型。
*/
class CodeVersion {
public:
	CodeVersion() :version(0), date("1900-01-01"), label("none") {}
	CodeVersion(int iVersion, string iDate, string iLabel) :version(iVersion), date(iDate), label(iLabel) {}
	// 保存代码
	Memento* save() {
		return new Memento(this->version, this->date, this->label);
		//这个方法就是保存状态。保存状态的原理即是返回一个新的备忘录对象指针。
	}
	// 回退版本
	void restore(Memento* memento) {
		//回退的原理即是通过传入的备忘录对象把记录的部分赋值回原对象。
		setVersion(memento->getVersion());
		setDate(memento->getDate());
		setLabel(memento->getLabel());
	}
	void setVersion(int iVersion) {
		version = iVersion;
	}
	int getVersion() {
		return version;
	}
	void setLabel(string iLabel) {
		label = iLabel;
	}
	string getLabel() {
		return label;
	}
	void setDate(string iDate) {
		date = iDate;
	}
	string getDate() {
		return date;
	}
private:
	int version; // 代码版本
	string date; // 代码提交日期
	string label;// 代码标签
};

// 管理者
/*
管理者对象的核心目的就是帮助我们管理备忘录对象。
一般来说，管理者对象只负责保存，但是不能修改。
因为我们可以实现undo和redo功能，所以一般来说管理者内部会有一个容器储存一堆的备忘录对象指针。
在当前语义下，原发类对象创建的备忘录指针必须被管理者管理。所以管理者对象需要负责备忘录对象的释放操作。
*/
class CodeManager
{
public:
	CodeManager() {
		mementoList.resize(10, nullptr);
	}
	CodeManager(const CodeManager&) = delete;
	CodeManager& operator=(const CodeManager&) = delete;
	~CodeManager() {
		for (auto memento : mementoList) {
			if (memento != nullptr) {
				cout << "desc" << endl;
				delete memento;
				memento = nullptr;
			}
		}
		/*
		在当前语义下，原发类对象创建的备忘录指针必须被管理者管理。所以管理者对象需要负责备忘录对象的释放操作。
		*/
	}
	void commit(Memento* m) {
		//也就是保存当前备忘录对象至容器。
		printf("提交：版本-%d, 日期-%s, 标签-%s\n", m->getVersion(), m->getDate().c_str(), m->getLabel().c_str());
		if (current_index > 10) {
			std::cout << "current list is full. It will cover the latest one" << std::endl;
			delete mementoList[0];
			mementoList[0] = m;
			current_index = 0;
		}
		else {
            delete mementoList[current_index];
			mementoList[current_index] = m;
			current_index++;
		}
		//mementoList.push_back(m);
	}
	// 切换到指定的版本，即回退到指定版本。此处逻辑是返回一个指定的版本的备忘录指针。
	Memento* switchToPointedVersion(int index) {
        current_index = index+1;
		return mementoList[index];
	}
	// 打印历史版本
	void codeLog() {
		for (int i = 0; i < current_index; i++) {
			if (mementoList[i] != nullptr) {
				printf("[%d]：版本-%d, 日期-%s, 标签-%s\n", i, mementoList[i]->getVersion(),
					mementoList[i]->getDate().c_str(), mementoList[i]->getLabel().c_str());
			}
		}
	}
private:
	vector<Memento*> mementoList; //容器储存备忘录对象指针。
	int current_index = 0; //当前版本的下标。
};


int main()
{
	CodeManager* Jungle = new CodeManager();

	CodeVersion* codeVer = new CodeVersion(1001, "2019-11-03", "Initial version");

	// 提交初始版本
	printf("提交初始版本:\n");
	Jungle->commit(codeVer->save());

	// 修改一个版本，增加了日志功能
	printf("\n提交一个版本，增加了日志功能:\n");
	codeVer->setVersion(1002);
	codeVer->setDate("2019-11-04");
	codeVer->setLabel("Add log funciton");
	Jungle->commit(codeVer->save());

	// 修改一个版本，增加了Qt图片浏览器
	printf("\n提交一个版本，增加了Qt图片浏览器:\n");
	codeVer->setVersion(1003);
	codeVer->setDate("2019-11-05");
	codeVer->setLabel("Add Qt Image Browser");
	Jungle->commit(codeVer->save());

	// 查看提交历史
	printf("\n查看提交历史\n");
	Jungle->codeLog();

	// 回退到上一个版本
	printf("\n回退到上一个版本\n");
	codeVer->restore(Jungle->switchToPointedVersion(1));
	// 查看提交历史
	printf("\n查看提交历史\n");
	Jungle->codeLog();



    //回退后提交新的版本
    printf("\n回退后提交新的版本\n");
    codeVer->setVersion(8888);
	codeVer->setDate("2088-88-88");
	codeVer->setLabel("new test");
	Jungle->commit(codeVer->save());

    printf("\n查看提交历史\n");
	Jungle->codeLog();


	delete Jungle;
	delete codeVer;
	Jungle = nullptr;
	codeVer = nullptr;

	return 0;
}