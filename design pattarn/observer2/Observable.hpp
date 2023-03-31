#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename> struct Observer;

template <typename T>
struct Observable{ //目标类，也就是被观察者
  std::vector<Observer<T>*> observers; //被观察者会有一个观察者的集合。
public:
  void notify(T& source, const std::string& field_name){ //通知
    for (auto observer : observers){
      observer->update(source, field_name); //通知给每一个观察者
    }
  }

  void subscribe(Observer<T>& observer){
    observers.push_back(&observer);
  }

  void unsubscribe(Observer<T>& observer)
  {
    observers.erase(
      remove(observers.begin(), observers.end(), &observer),
      observers.end()
    );
  }
};


