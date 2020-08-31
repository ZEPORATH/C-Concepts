/**
 * https://www.hackerrank.com/challenges/attribute-parser/problem
*/

/*
Sample Input:

4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value

Sample Output:
Name1
Not Found!
HelloWorld
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,q;
    cin >> n >> q;
    vector<string> hrml{}, query{};
    for (int i=0; i<n; i++)
    {
        string temp;
        getline(cin, temp);
        hrml.push_back(temp);
    }

    for (int i=0; i<q; i++)
    {
        string temp;
        getline(cin, temp);
        query.push_back(temp);
    }
    cin.ignore();
    unordered_map<string, string> map {};
    vector<string> tag {};
    for (int i=0; i<n;i++)
    {
        cout << hrml[i] << endl;
        string temp = hrml.at(i);
        temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '>'),  temp.end());
        if (temp.substr(0,2) == "</")
        {
            tag.pop_back(); 
        }
        else
        {
            std::stringstream sstream;
            sstream.str("");
            sstream << temp;
            char ch;
            string t1, p1, v1;
            sstream >> ch >> t1 >> p1 >> ch >> v1;
            string temp1 = "";
            if(tag.size() > 0)
            {
                temp1 = *tag.rbegin();
                temp1 = temp1+"."+t1;
            }
            else
            {
                temp1 = t1;
            }
            tag.push_back(temp1);
            map[*tag.rbegin()+"~"+p1] = v1;
            while (sstream)
            {
                sstream >> p1 >> ch >> v1;
                map[*tag.rbegin()+"~"+p1] = v1;
            }
            
            
        }
        
    }

    for (auto pair: map)
    {
        cout << pair.first << ":  " << pair.second << endl;
    }
    for (int i=0; i<q;i++)
    {
        cout << query[i] << endl;
        if (map.find("."+query[i]) == map.end())
            cout << "Not Found!\n" << endl;
        else
        {
            cout << map["."+query[i]] << "\n";
        }
        
    }

    return 0;
}

