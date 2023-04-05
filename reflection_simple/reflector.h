#pragma once

#include <string>
#include <map>
#include <iostream>
#include <functional>
/********************所有需要实现反射的类需要继承它************************/
class ReflectObject { 
public:
	virtual ~ReflectObject(){}
};
/************************************************************************/


/******************对象工厂抽象类，用来生成对象实例************************/
class ObjectFactory {
public:
	ObjectFactory(){ std::cout << "ObjectFactory()" << std::endl; }
	virtual ~ObjectFactory(){ std::cout << "~ObjectFactory()" << std::endl; }
	virtual ReflectObject* newInstance() = 0;
};
/************************************************************************/


/***********反射器，用来管理（对象名，对象工厂）的映射关系******************/

class Reflector
{
public:
    static Reflector& reflector();
    Reflector(const Reflector&) = delete;
    Reflector& operator= (const Reflector&) = delete;
	void registerFactory(const std::string& className, ObjectFactory* function);

	ReflectObject* getNewInstance(const std::string& className);
	//void* getNewInstance(const std::string& className);
private:
    Reflector();
	~Reflector();
	std::map<std::string, ObjectFactory*> objectFactories;
};
/************************************************************************/


/**********************获取反射器实例，全局唯一****************************/
//Reflector& reflector();
/************************************************************************/


/***********需要被反射的类，需要在其对应的 cpp 文件中进行反射声明***********/
#define REFLECT(name)\
class ObjectFactory_##name : public ObjectFactory{\
public:\
	ObjectFactory_##name(){ std::cout << "ObjectFactory_" << #name << "()" << std::endl; }\
	virtual ~ObjectFactory_##name(){ std::cout << "~ObjectFactory_" << #name << "()" << std::endl; }\
	ReflectObject* newInstance() {\
		return new name(); \
	}\
}; \
Reflector::reflector().registerFactory(#name, new ObjectFactory_##name());
// class Register_##name{\
// public:\
// 	Register_##name(){\
// 		Reflector::reflector().registerFactory(#name, new ObjectFactory_##name()); \
// 	}\
// };\
// Register_##name register_##name;
/************************************************************************/



/***********************根据类名获取对象实例******************************/
template<typename T, typename... Args>
T* getNewInstance(const std::string& className) {
	return static_cast<T*>(Reflector::reflector().getNewInstance(className));
}
/************************************************************************/
