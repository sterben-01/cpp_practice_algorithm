#pragma once
#include "PersonBuilder.h"

class PersonJobBuilder : public PersonBuilderBase //具体建造者1
{
  typedef PersonJobBuilder Self;
public:
  PersonJobBuilder(Person& person) : PersonBuilderBase (person){}

  Self& at(std::string company_name)
  {
    person.company_name = company_name;
    return *this;
  }

  Self& as_a(std::string position)
  {
    person.position = position;
    return *this;
  }

  Self& earning(int annual_income)
  {
    person.annual_income = annual_income;
    return *this;
  }
};