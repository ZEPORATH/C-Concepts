#include <iostream>
#include <typeinfo>  //for 'typeid' to work

class Person {
public:
   // ... Person members ...
   virtual ~Person() {}
};

class Employee : public Person {
   // ... Employee members ...
};

int main () {
   Person person;
   Employee employee;
   Person *ptr = &employee;
   // The string returned by typeid::name is implementation-defined
   std::cout << typeid(person).name() << std::endl;   // Person (statically known at compile-time)
   std::cout << typeid(employee).name() << std::endl; // Employee (statically known at compile-time)
   std::cout << typeid(ptr).name() << std::endl;      // Person * (statically known at compile-time)
   std::cout << typeid(*ptr).name() << std::endl;     // Employee (looked up dynamically at run-time
                                                      //           because it is the dereference of a
                                                      //           pointer to a polymorphic class)
    employee = *(dynamic_cast<Employee*>(&person));
    if (&employee)
    {
        puts("Work\n");
    }
    else
    {
        puts("Does not Works\n");
    }
}