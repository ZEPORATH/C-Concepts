/**
 * Given a string and length K, output a list of sub strings with K-1 distinct characters in alphabetical order
 * for eg:
 * Input:
 *   democracy 5
 * Output:
 *   cracy
 *   ocrac
*/

#include <bits/stdc++.h>

using namespace std;




/*
 * Complete the 'foo' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING inputStr
 *  2. INTEGER num
 */

vector<string> foo(string inputStr, int num) {
    vector<string> res{};
    unordered_map<char, int> map;
    int s = 0, k = num, l = inputStr.size();
    if (l<=0 || k == 0)
        return res;

    else 
    {
       for (int i=0; i<k; i++)
         map[inputStr[i]]++;
        if (map.size() == k-1)
            res.insert(std::upper_bound(res.begin(), res.end(),inputStr.substr(0,k) ), inputStr.substr(0,k));
        for (int i=k; i<l; i++)
        {
            map[inputStr[i]]++;
            map[inputStr[i-k]]--;
            
            if (map[inputStr[i-k]] == 0)
                map.erase(inputStr[i-k]);

            if (map.size() == k-1)
                res.insert(std::upper_bound(res.begin(), res.end(), inputStr.substr(i-k+1)), inputStr.substr(i-k+1,k));
        }

        return res;
    }
}

int main()
{
   auto res = foo("democracy", 5);
   for (auto a: res)
    cout << a << "\n";

}
