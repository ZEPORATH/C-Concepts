/**
 * Copy Constructor - mostly used to implement a deep copy of passed object, or a personalized copy
 * Help: https://www.geeksforgeeks.org/copy-constructor-in-cpp/
 * */

#include <iostream>
#include <vector>
using namespace std;

struct advancedVector
{
    uint64_t size() {return m_vector->size();}
    uint64_t length() {return m_vector->size();}

    friend uint64_t len(const advancedVector& vec);

    advancedVector (int len=0)
    {
        m_vector = new vector<int>(len);
    }

    advancedVector (const advancedVector& obj)
    {
        // m_vector = new vector<int>();
        // copy(obj.m_vector->begin(), obj.m_vector->end(), back_inserter(*m_vector));
        m_vector = new vector<int>(*obj.m_vector);
    }
    //Implement cyclic array indexing like python lists.

    int& operator [] (const int& i)
    {
        if (abs(i)>m_vector->size())
        {
            cerr << "Index out of bounds" << endl;
            throw std::out_of_range("Index out of bounds");
        }
        else
        {
            if (i<0)
            {
                return (*m_vector)[ (m_vector->size() + i) ];
            }
            else
            {
                return (*m_vector)[i];
            }
            
        }   
    }

    void append(int i)
    {
        m_vector->push_back(i);
    }

    advancedVector& operator << ( int i)
    {
        m_vector->push_back(i);
        return *this;
    }

    void printVec()
     {
         cout << "\n[ ";
         for (auto& elem: *m_vector)
            cout << elem << ", ";
        cout << "]\n";
     }

    ~advancedVector() {delete m_vector;}
private:
    vector<int>* m_vector;
};

uint64_t len(const advancedVector& vec) {return vec.m_vector->size();}

int main(int argc, char const *argv[])
{
    advancedVector vec;
    vec << 1 << 2 << 3 << 4 << 5;
    vec.printVec();
    auto vec2 = vec;
    vec2 << 6;
    vec.printVec();
    vec2.printVec();
    return 0;
}
