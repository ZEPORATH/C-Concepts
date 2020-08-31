/**
 * C++ Class Templates
 * https://www.hackerrank.com/challenges/c-class-templates/problem
 * 
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/*Write the class AddElements here*/

template<typename T>
class AddElements
{
    T element1;
public:
    AddElements(T element): element1(element){}
    T add(T elem){return element1+elem;}
    template<typename Q = T>
    typename std::enable_if<std::is_same<Q, string>::value, string>::type
    concatenate(string eleme)
    {
        return element1 + eleme;
    }
};

int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
