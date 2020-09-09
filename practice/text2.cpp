#include <bits/stdc++.h>

bool position_set(int i, int pos)
{
    return (i ^ 1<<pos) ? false : true;
}

int main(int argc, char const *argv[])
{
    /* code */
    std::cout << std::boolalpha << position_set(4, 0) << std::endl;
    std::cout << std::boolalpha << position_set(4, 2) << std::endl;
    std::cout << std::boolalpha << position_set(4, 1) << std::endl;
    return 0;
}
