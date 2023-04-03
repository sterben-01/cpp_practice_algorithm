#include "objectstructure.h"



int main(){
    Element* apple = new Apple();
    Element* badge = new Badge();

    objectStructure container;
    container.addElement(apple);
    container.addElement(badge);

    Visitor* people = new People();
    Visitor* boss = new Boss();


    container.accept(people);
    container.accept(boss);


    delete apple;
    delete badge;
    delete people;
    delete boss;
}