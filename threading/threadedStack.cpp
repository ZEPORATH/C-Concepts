#include <iostream>
#include <exception>
#include <thread>
#include <memory>
#include <stack>
#include <cstdlib>

#if defined(_GLIBCXX_HAS_GTHREADS) && defined(_GLIBCXX_USE_C99_STDINT_TR1)
#endif

struct empty_stack: std::exception
{
    const char* what() const throw();

};

template<typename T>
class threadedStack
{
private:
    std::stack<T> data;
    mutable std::mutex m;
public:
    threadedStack() {}

    threadedStack(const threadedStack& other)
    {
        std::lock_guard<std::mutex> lock(other.m);
        data = other.data;
    }
    threadedStack& operator = (const threadedStack&) = delete;

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }

    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty()) throw empty_stack();
        std::shared_ptr<T> const res(std::make_shared<T>(data.top()));
        data.pop();
        return res;
    }

    void pop(T& value)
    {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty()) throw empty_stack();
        value = data.top();
        data.pop();
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};

int main(int argc, char const *argv[])
{
    threadedStack<int> stack;
    stack.push(23);
    stack.push(3);
    stack.push(-103);
    stack.push(-23);
    while (!stack.empty())
    {
        std::cout << stack.pop() << " ";
    }
    
    return 0;
}
