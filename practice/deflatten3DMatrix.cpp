#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // Flat[x*HEIGHT*DEPTH + y*DEPTH + DEPTH] = Original[x, y, z], assuming Original[HEIGHT,WIDTH,DEPTH] 

    int arr[24] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
    int h = 2, w = 4, c= 3;

    for (int i = 0; i<h;  i++)
    {    for (int j = 0; j<w; j++)
       {     for (int z=0; z<c; z++)
            {
                cout << arr[i*h*c + j*c + z] << ",";
            }
        cout << "\t";}
    cout << endl;}
    return 0;
}