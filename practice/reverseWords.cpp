/**
 * Reverse words in a given string
 *  
    Input: s = “geeks quiz practice code”
    Output: s = “code practice quiz geeks”

    Input: s = “getting good at coding needs a lot of practice”
    Output: s = “practice of lot a needs coding at good getting” 
*/

#include <sstream>
#include <string>
#include <vector>
#include <iterator> 
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string inputStr;
    getline(cin, inputStr);
    istringstream iss(inputStr);
    vector<string> vec(std::istream_iterator<string>{iss}, 
                        std::istream_iterator<string>());


    string outStr;
    for (auto rit = vec.rbegin(); rit!=vec.rend(); rit++)
        outStr.append(*rit).append(" ");
    cout << outStr << "\n";
    return 0;
}
