#ifndef __OBJECTSTRUCTURE_H__
#define __OBJECTSTRUCTURE_H__
#include <vector>
#include "visitor.h"
#include "element.h"


struct objectStructure{ //对象结构类

    objectStructure() = default;
    void addElement(Element* ele){
        my_elements.push_back(ele);
    }

    void accept(Visitor* visitor){
        for(int i = 0; i < my_elements.size(); i++){
            my_elements[i]->accept(visitor);
        }
    }

    vector<Element*> my_elements; //容器保存元素。
};

#endif
