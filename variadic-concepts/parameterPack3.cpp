#include <iostream>
#include <utility>

int add (int a, int b)
{
    return a+b;
}

template<typename Callable, typename ...pArgs>
auto bindValues(Callable callable, pArgs ... params)
{
    return [lcallable = std::move(callable), ...my_params = std::move(params)]()
    {
        return lcallable(my_params...);
    };
}

int main(int argc, char const *argv[])
{
    auto bindVal = bindValues(add, 1, 2);
    std::cout << bindVal() << "\n";
    return 0;
}
