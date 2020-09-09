#include <bits/stdc++.h>

bool position_set(int i, int pos)
{
    return !(i & 1<<pos)
}

int main(int argc, char const *argv[])
{
    /* code */
    std::cout << std::boolalpha << position_set(10, 0);
    return 0;
}
