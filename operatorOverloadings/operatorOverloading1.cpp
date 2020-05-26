/***
 * This is sample for new and delete operator overloading
 *
 * */
#include <bits/stdc++.h>
using namespace std;

struct operatorOverloading1
{
    int member1;
    static int count;
    operatorOverloading1(int f=INT_MIN): member1(f) {};
    
    void* operator new (size_t size)
    {
        cout << "Calling new operator with size: " << size << endl;
        operatorOverloading1::count += 1;
        void* _ptr = ::new operatorOverloading1();
        return _ptr;
    }

    void operator delete(void* p)
    {
        cout << "Delete will be called " << endl;
        free(p);
        operatorOverloading1::count -= 1;
    }
};

int operatorOverloading1::count = 0;

int main(int argc, char const *argv[])
{
    operatorOverloading1 opV;
    opV.member1 = 9;

    auto nImpl = new operatorOverloading1();
    cout << operatorOverloading1::count << endl;
    delete nImpl;
    cout << operatorOverloading1::count << endl;

    return 0;
}
