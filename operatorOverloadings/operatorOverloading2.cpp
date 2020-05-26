/***
 * this is the sample for operator = overloading 
 * 
 * */
#include <bits/stdc++.h>
using namespace std;

struct operatorOverloading2
{
    int member1;

    operatorOverloading2(int i=INT_MIN): member1(i){};

    void operator = (const char* p)
    {
        member1 = atoi(p);
    }

    operatorOverloading2 operator = (const operatorOverloading2& rhs)
    {
        operatorOverloading2 _obj;
        _obj.member1 = rhs.member1;
        return _obj;
    }

};

int main(int argc, char const *argv[])
{
    operatorOverloading2 ovl2;
    ovl2 = "123";
    cout << ovl2.member1 << endl;
    auto ovl3 = ovl2;
    cout << ovl3.member1 << endl;

    return 0;
}
