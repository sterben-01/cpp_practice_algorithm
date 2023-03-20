#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

int main(){ //这个main就是指挥者。负责整体的组装
  Person p = Person::create()
    .lives().at("123 London Road").with_postcode("SW1 1GB").in("London")
    .works().at("PragmaSoft").as_a("Consultant").earning(10e6);

  cout << p << endl;
  getchar();
  return 0;
}