/**
 * Overloading stream extraction operator << and >>. 
 * 
 * */

#include <bits/stdc++.h>
using namespace std;

ostream& operator<<(ostream& streamerObj, vector<string>& data)
{
    streamerObj << "\n[ ";
    for(auto& elem: data)
        streamerObj << elem << ", ";
    streamerObj << "\b\b ]\n";
    return streamerObj;
}

int main(int argc, char const *argv[])
{
    vector<string> name_vec = {"Hari", "Shankar", "Sahu"};
    cout << name_vec ;
    return 0;
}
