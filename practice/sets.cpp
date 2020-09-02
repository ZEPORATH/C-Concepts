/**
 * https://www.hackerrank.com/challenges/cpp-sets/problem
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int Q=0, opCode=0, val = 0;
    cin >> Q;
    set<int> s{};
    for (int i=0; i< Q; i++)
    {
        cin >> opCode >> val;
        switch(opCode)
        {
            case 1: s.insert(val); break;
            case 2: s.erase(val); break;
            case 3: if (s.find(val) != s.end())
                        cout << "Yes" << "\n";
                    else 
                        cout << "No" << "\n";
                    break;
        }
    } 
    return 0;
}



