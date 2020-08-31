#include <iostream>
#include <sstream>

using namespace std;

void tprintf(const char* format)
{
    std::cout << format;
}

template<typename T, typename ... Targs>
void tprintf(const char* format, T value, Targs... Fargs)
{
    // cout << __PRETTY_FUNCTION__ << "\n";
    for (; *format!= '\0'; format++)
    {
        if (*format == '%')
        {
            cout << value;
            tprintf(format+1, Fargs...);
            return;
        }
        cout << *format;
    }
}

int main(int argc, char const *argv[])
{
    tprintf("% world% %\n", "Hello ", "!", 123);
    return 0;
}
