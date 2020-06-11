/***
 * Virtual keyword is responsible in correct invoking of methods according to assigned type at the runtime
 * It helps in runtime polymorphism, 
 * We need to explore what virtual is usefull for , like in destructors,
 *
 * Question: Why we can point a derived object from base pointer, but not vice-versa.
 * Question: If we have a pointer based member, and the pointer are pointing to some data, why after calling a delete we are still
 * able to invoke the method/member variable.
 * 
 * */

#include <iostream>
struct base
{
    /* data */
    // int* member1 = nullptr;
    // base(int& a): member1(&a) {}     
    int member1;
    base(int& a): member1(a) {} 
    // ~base(){delete member1;} //This will cause exception, why
    // ~base() = default; //Use the default destructor
    virtual ~base() 
    {
        puts("base class destructor\n");
        // if (member1) 
        //     delete member1;
    }
};

struct derived0: base
{
    // int* member2 = nullptr;
    // derived0(int& a): base(a), member2(&a) {}
    int member2;
    int member3;
    int member4;
    int member5;
    int member6;
    int member7;
    derived0(int& a): base(a), member2(a) {}
    // ~derived0() = default;
    ~derived0() 
    {
        puts("derived0 class destructor\n"); 
        // if (member2)
        //     delete member2; //this used to crash
    }
};

int main(int argc, char const *argv[])
{
    int a  = 12;
    base* bp = new base(a);
    derived0 *dr0 = new derived0(a);

    delete dr0; // Doesn't set this to nullptr
    delete bp;
    bp = dr0;
    // std::cout << *(dr0->member2) << std::endl;
    std::cout << (dr0->member2) << std::endl;
    return 0;
}

