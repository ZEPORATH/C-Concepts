/**
 * https://www.hackerrank.com/challenges/vector-sort/problem
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void insertSorted(vector<T>& iVec, T&data)
{
    iVec.insert(std::upper_bound(iVec.begin(), iVec.end(), data), data);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> iVec{};
    for (int i=0; i<n;i++)
    {
        int temp;
        cin >> temp;
        insertSorted<int>(iVec, temp);
        // cin >> iVec.at(i);
    }
    // std::sort(iVec.begin(), iVec.end());
    for(auto i: iVec)
        cout << i << " ";
    cout << "\n";
    return 0;
}