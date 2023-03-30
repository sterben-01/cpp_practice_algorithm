#include "codemanager.h"
#include "memento.h"

CodeManager::CodeManager() {
    mementoList.resize(10, nullptr);
}
CodeManager:: ~CodeManager() {
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
void CodeManager::commit(Memento* m) {
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
Memento* CodeManager::switchToPointedVersion(int index) {
    current_index = index+1;
    return mementoList[index];
}
// 打印历史版本
void CodeManager::codeLog() {
    for (int i = 0; i < current_index; i++) {
        if (mementoList[i] != nullptr) {
            printf("[%d]：版本-%d, 日期-%s, 标签-%s\n", i, mementoList[i]->getVersion(),
                mementoList[i]->getDate().c_str(), mementoList[i]->getLabel().c_str());
        }
    }
}
