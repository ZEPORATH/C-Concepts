/**
 * C++ Class Template Specialization  
 * https://www.hackerrank.com/challenges/cpp-class-template-specialization/problem
 * */

#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

// Define specializations for the Traits class template here.

template <typename T>
struct Traits
{
                
                
    // using enum Fruit;
    // using enum Color;
public:
    static string name(int index)
    {
        if (std::is_same<Fruit, T>::value)
        {
            auto cast_index = static_cast<Fruit>(index);
            switch (cast_index) 
            {
                case Fruit::apple : return "apple";
                case Fruit::orange: return "orange";
                case Fruit::pear  : return "pear";
                default: return "unknown";
            }
        }
        else if (std::is_same<Color, T>::value) 
        {
            // using enum Color;
            auto cast_index = static_cast<Color>(index);
            switch (cast_index) 
            {
                case Color::green : return "green";
                case Color::orange: return "orange";
                case Color::red   : return "red";
                default:            return "unknown";
            }
        }
    }
};

int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
