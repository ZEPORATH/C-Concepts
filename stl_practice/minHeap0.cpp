#include <bits/stdc++.h>

int main(int argc, char const *argv[])
{
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
    pq.push(10);
    pq.push(3);
    pq.push(7);
    pq.push(6);
    pq.push(1);
    pq.push(30);

    while (pq.empty() == false)
    {
        std::cout << pq.top() << " " << std::abs;
        pq.pop();
    }
    
    return 0;

}
