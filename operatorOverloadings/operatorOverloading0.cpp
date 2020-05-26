/***
 * This is a sample for operator () overloading //()-Function call Operator
 * */
#include <bits/stdc++.h>

using namespace std;

struct SomeObject 
{
    int foo;
    SomeObject(int foo=INT_MIN): foo(foo) {};

    // SomeObject operator()(int a)
    // {
    //     cout << "Invoked () "<< endl;
    //     SomeObject obj;
    //     obj.foo = a;
    //     return obj;
    // }

    SomeObject* operator() (int a)
    {
        cout << "Invoked ()* " << endl;
        auto obj = new SomeObject();
        obj->foo = a;
        return obj;
    }
};

int main(int argc, char const *argv[])
{
    SomeObject obj;
    obj.foo = 11;
    auto D2 = obj(1);
    cout << D2->foo << endl;
    return 0;
}
