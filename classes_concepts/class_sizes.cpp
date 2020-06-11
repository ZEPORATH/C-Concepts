/**
 * 
 * This poc is to understand the basics of class sizes in memory, we will see the following points:
 * 
 * 1) size due to virtual functions,
 * 2) pointers based member function
 * 3) static   member function to class size
 * 4) vtable size
 * 5) printing a class as present in memory.
 * 6) O size classes
 * 7) size of abastract classes.
 * 5) printing a hierarchial class as present in memory.
 * 
 * */

#include <iostream>

using namespace std;

struct base
{
    /* data */
    int member1;        //Size 4bytes
    int member2;        //Size 4bytes
    int member3;        //Size 4bytes
    static int member7; // Adds no size to class
    void method1() {}   // Adds no size to class
    int method2() {}    // Adds no size to class
    base() = default;
    virtual ~base() {}
};
struct  derived0: base
{
    int member4; //Size 4bytes
    int member5; //Size 4bytes 
    virtual ~derived0() {}

};

int main(int argc, char const *argv[])
{
    derived0 d1;
    base b1;
    
    cout << "Size of b1 " << sizeof(b1) << " &b1 " << &b1 << endl;
    cout << "Size of d1 " << sizeof(d1) << endl;
    
    return 0;
}
