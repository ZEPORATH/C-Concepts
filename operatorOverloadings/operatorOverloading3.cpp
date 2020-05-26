/***
 * Overloading subscript or Array Index [] operator
 * */
#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;

struct advancedVector
{
    uint64_t size(){return m_vector.size();}
    uint64_t length() {return m_vector.size();}

    friend uint64_t len(const advancedVector& vec);

    //Implement cyclic array indexing like python lists.

    int& operator [] (const int& i)
    {
        if (abs(i)>m_vector.size())
        {
            cerr << "Index out of bounds" << endl;
            throw std::out_of_range("Index out of bounds");
        }
        else
        {
            if (i<0)
            {
                return m_vector[ (m_vector.size() + i) ];
            }
            else
            {
                return m_vector[i];
            }
            
        }   
    }

    void append(int i)
    {
        m_vector.push_back(i);
    }

     void printVec()
     {
         cout << "\n[ ";
         for (auto& elem: m_vector)
            cout << elem << ", ";
        cout << "]\n";
     }

private:
    vector<int> m_vector;
};

uint64_t len(const advancedVector& vec) {return vec.m_vector.size();}

int main(int argc, char const *argv[])
{
    advancedVector av;
    av.append(1);
    av.append(2);
    av.append(3);
    av.append(4);
    av.append(5);
    av.printVec();
    cout << "Size of array: " << len(av) << endl;
    
    cout << "Reading index 2: " << av[2] << endl;
    cout << "Reading index -2: " << av[-2] << endl;
    try
    {
        cout << "Reading index -13: " << av[-13] << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        cout << "Reading index 13: " << av[13] << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
