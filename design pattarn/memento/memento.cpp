#include "memento.h"
#include "codeversion.h"
//备忘录类。
/*
在当前业务需求下，我们只需要保存原发器类的版本，日期和标签三个属性
*/


Memento::Memento(int iVersion, string iDate, string iLabel) :version(iVersion), date(iDate), label(iLabel) {}
Memento::Memento(CodeVersion* code):version(code->getVersion()), date(code->getDate()), label(code->getLabel()) {}
void Memento::setVersion(int iVersion) {
    version = iVersion;
}
int Memento::getVersion() {
    return version;
}
void Memento::setLabel(string iLabel) {
    label = iLabel;
}
string Memento::getLabel() {
    return label;
}
void Memento::setDate(string iDate) {
    date = iDate;
}
string Memento::getDate() {
    return date;
}
