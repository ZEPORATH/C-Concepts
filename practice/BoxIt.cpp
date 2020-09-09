#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box {
private:
    int l,b,h;
public:
    Box(){l=0;b=0;h=0;}
    Box(int len,int breadth,int height): l(len),b(breadth),h(height){}
    Box(const Box& b1)
    {
        l = b1.getLength();
        b = b1.getBreadth();
        h = b1.getHeight();
    }
    int getLength() const {return l;}; // Return box's length
    int getBreadth () const {return b;}; // Return box's breadth
    int getHeight () const {return h;};  //Return box's height
    long long CalculateVolume() {
        long long res = 1;
        res = res*l*b*h;
        return res;
    } // Return the volume of the box
    bool operator<(Box& b1)
    {
        if (l< b1.getLength()) return true;
        if (b < b1.getBreadth() && l == b1.getLength()) return true;
        if (h < b1.getHeight() && l == b1.getLength() && b == b1.getBreadth()) return true;
        return false;
    }
    friend ostream& operator<<(ostream& out, const Box& B)
    {
        out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight() ;
        return out;
    }
};
