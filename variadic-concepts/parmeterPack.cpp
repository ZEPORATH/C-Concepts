#include <iostream>
using namespace std;

void print()
{
    cout << "I am empty function and I am called at last" << endl;
}

template<typename T, typename... pArgs>
void print(T var1, pArgs... var2)
{
    cout << var1 << endl;
    print(var2...);
}

int main()
{
    print(1, 2, 34, "Help I am with idiot", 90, 1.3f, 987943, "JHELODJMGF\toeir");
    return 0;
}
