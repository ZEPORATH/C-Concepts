#include <iostream>
struct base
{
    int* member1 = nullptr;
    base(int& a): member1(&a) {}     

    // ~base(){delete member1;} //This will cause exception, why
    // ~base() = default; //Use the default destructor
    virtual ~base() 
    {
        puts("base class destructor\n");
        // if (member1) 
        //     delete member1;
    }
};

struct derived0: base
{
    int* member2 = nullptr;
    derived0(int& a): base(a), member2(&a) {}

    // ~derived0() = default;
    ~derived0() 
    {
        puts("derived0 class destructor\n"); 
        // if (member2)
        //     delete member2; //this used to crash - Give a proper reasoning
    }
};

int main(int argc, char const *argv[])
{
    int a  = 12;
    base* bp = new base(a);
    derived0 *dr0 = new derived0(a);
    // printf("Printing object: %d\n", dr0);
    // printf("Printing object: %s, size: %ld, sizeof int: %ld\n", (char*)dr0, sizeof(*dr0), sizeof(int));

    delete dr0; // Doesn't set this to nullptr Line 39 - fun; wierd behaviour
    delete bp;
    bp = dr0;
    std::cout << *(dr0->member2) << std::endl;
    printf("Printing object: %s",(char*)dr0);
    return 0;
}
