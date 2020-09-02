/**
 * https://www.hackerrank.com/challenges/vector-erase/problem
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> iVec{};
    for (int i=0; i<n;i++)
    {
        int temp;
        cin >> temp;
        iVec.push_back(temp);
    }
    int posIdx = 0;
    cin >> posIdx;
    iVec.erase(iVec.begin() + posIdx-1);
    int st = 0, end = 0;
    cin >> st >> end;
    iVec.erase(iVec.begin() + st-1, iVec.begin() + end-1);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    cout << iVec.size() << "\n"; 
    for (auto a: iVec)
        cout << a << " ";
    cout << "\n";
    return 0;
}
