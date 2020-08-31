#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>

using namespace std;

template<typename ... Param>
std::vector<std::string> to_string(const Param& ... param)
{
    cout << __PRETTY_FUNCTION__ << "\n";
    const auto to_string_impl = [] (const auto& p) 
    {
        cout << __PRETTY_FUNCTION__ << "\n";
        std::stringstream ss;
        ss << p;
        return ss.str();
    };
    
    return {to_string_impl(param) ...}; //Indializing with the vector with initialization list
}

int main()
{
    const auto vec = to_string("hello", 1, 5.3, "world", 1.3f, 1, 2, 3 ,4, 1500, "bob");

    for (const auto &o: vec)
    {
        cout << o << "\t";
    }
    
    cout << "\n";
    
    return 0;
}