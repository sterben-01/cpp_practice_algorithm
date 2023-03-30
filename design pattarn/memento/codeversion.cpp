#include "memento.h"
#include "codeversion.h"


CodeVersion::CodeVersion() :version(0), date("1900-01-01"), label("none") {}
CodeVersion::CodeVersion(int iVersion, string iDate, string iLabel) :version(iVersion), date(iDate), label(iLabel) {}
// 保存代码
Memento* CodeVersion::save() {
    //return new Memento(this->version, this->date, this->label);
    return new Memento(this);
    //这个方法就是保存状态。保存状态的原理即是返回一个新的备忘录对象指针。
}
// 回退版本
void CodeVersion::restore(Memento* memento) {
    //回退的原理即是通过传入的备忘录对象把记录的部分赋值回原对象。
    setVersion(memento->getVersion());
    setDate(memento->getDate());
    setLabel(memento->getLabel());
}
void CodeVersion::setVersion(int iVersion) {
    version = iVersion;
}
int CodeVersion::getVersion() {
    return version;
}
void CodeVersion::setLabel(string iLabel) {
    label = iLabel;
}
string CodeVersion::getLabel() {
    return label;
}
void CodeVersion::setDate(string iDate) {
    date = iDate;
}
string CodeVersion::getDate() {
    return date;
}
