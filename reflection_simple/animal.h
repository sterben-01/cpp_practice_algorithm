#pragma once
#include "reflector.h"


class Animal : public ReflectObject{
public:
	Animal();
	virtual ~Animal();
	virtual void bark();
};

