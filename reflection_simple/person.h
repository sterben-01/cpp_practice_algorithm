#pragma once
#include "reflector.h"


class Person : public ReflectObject{
public:
	Person();
	virtual ~Person();
	virtual void show();
};

