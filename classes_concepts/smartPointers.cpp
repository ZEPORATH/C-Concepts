/***
 * Smart pointers - to automate garbage collections.
 * 
 * */
#include <iostream>
#include <bits/stdc++.h>

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
    
    virtual ~advancedVector() 
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    
    advancedVector& operator << ( int i) 
    {
        // cout << __PRETTY_FUNCTION__ << endl;
        m_vector.push_back(i);
        return *this;
    }

private:
    vector<int> m_vector;
};

uint64_t len(const advancedVector& vec) {return vec.m_vector.size();}


int main(int argc, char const *argv[])
{
    /* code */
    unique_ptr<advancedVector> obj1 = make_unique<advancedVector>();
    *obj1 << 1 << 2 << 3 << 4 << 5;
    obj1->printVec();

    unique_ptr<advancedVector> obj2 = move(obj1); //We cannot obj2
    obj2->printVec();

    shared_ptr<advancedVector> obj3 = make_shared<advancedVector>(*obj2);
    auto obj4 = obj3; //No deepcopy

    *obj4 << 5;

    obj4->printVec(); 
    obj3->printVec();

    return 0;
}
