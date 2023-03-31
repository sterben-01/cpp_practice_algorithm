#pragma once
#include <string>

template <typename T> //观察者基类
struct Observer
{
  virtual void update(T& source, const std::string& field_name) = 0; //观察者基类有一个update用来通知其他的观察者
};


