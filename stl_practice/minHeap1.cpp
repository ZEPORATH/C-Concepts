//Sort the boxes in increasing order.
#include <bits/stdc++.h>
struct Box{
    int b,l, h;
    Box(int b, int l, int h): b(b),l(l), h(h) {}
    int get_l() {return l;}
    int get_b() {return b;}
    int get_h() {return h;}

};

struct  Volumecomparator
{
    int operator () (const Box& b1, const Box& b2)
    {
        if (b1.b * b1.l * b1.h > b2.b * b2.l * b2.h)
            return true;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    std::priority_queue<Box, std::vector<Box>, Volumecomparator> pq;
    pq.push(Box(12, 2, 3));
    pq.push(Box(2, 12, 5));
    pq.push(Box(2, 2, 1));
    pq.push(Box(122, 12, 13));
    pq.push(Box(12, 21, 31));

    while (pq.empty() == false) 
    { 
        Box p = pq.top(); 
        std::cout << "(" << p.get_b() << ", " << p.get_h() << ", " << p.get_l() << ")"; 
        std::cout << std::endl; 
        pq.pop(); 
    } 
    return 0;
}
