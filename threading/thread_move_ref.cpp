/*
This code is to create and understand the scenario of iterating through a vector of something and passing the same thing to a new thread.
Observation while coding for offile QList<QFileInfo> not all FileInfo passed to the threads were unique Bug_2058
*/

#include <iostream>
#include <thread>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define fn_print     std::cout << __PRETTY_FUNCTION__ << std::endl;

void threadFn_0(int data, std::vector<int>& outList)
{
    // fn_print
    // std::cout << std::this_thread::get_id() << " " << data << std::endl;
    outList.push_back(data);
}

bool isStrictlyIncreasing(const std::vector<int>& outList)
{
    fn_print;
    int i = outList[0];
    bool res = true;
    for(auto a: outList)
    {
        if(i == a)
            i+=1;
        else
        {
            std::cout << "A is: " << a << " and i is: " << i << std::endl;
            res =  false;
            i+=1;
        }
        
    }
    return res;
}
void printRepeating(std::vector<int>arr, int size)  
{  
    int i;  
      
    std::cout << "The repeating elements are:";  
          
    for(i = 0; i < size; i++)  
    {  
        if(arr[abs(arr[i])] > 0)  
            arr[abs(arr[i])] = -arr[abs(arr[i])];  
        else
            std::cout<<" " << abs(arr[i]) <<" ";  
    }      
}
int main(int argc, char const *argv[])
{
    /* code */
    fn_print
    std::vector<std::thread> ThreadVector;
    std::vector<int> list(9999), outList;
    
    // list.reserve(15);
    int n = 1;
    std::generate(list.begin(), list.end(), [&n](){return n++;});
    
    for (auto& elem: list)
    {
        // int elemi = elem;
        ThreadVector.emplace_back(threadFn_0, elem, std::ref(outList));
    }

    for (auto &t: ThreadVector)
        t.join();

    // for (auto elem: outList)
    //     std::cout << elem << ", ";
    // std::cout << std::endl;

    std::cout << std::boolalpha << isStrictlyIncreasing(outList) << "\n";
    printRepeating(outList, outList.size());
    
    return 0;
}
