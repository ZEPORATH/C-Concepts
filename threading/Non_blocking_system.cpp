#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;
#define __fname __PRETTY_FUNCTION__

static bool completed  = false;

class Non_blocking_system
{
private:
    /* data */
public:
    Non_blocking_system(/* args */);
    ~Non_blocking_system();
    static bool canDoSomeOperation();
    static void someOperation(void(*callback_fn)(int status));
    static void onSomeOperationFinished(int status = 0);
};

Non_blocking_system::Non_blocking_system(/* args */)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

Non_blocking_system::~Non_blocking_system()
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void Non_blocking_system::someOperation(void( *callback_fn) (int))
{
    cout << __PRETTY_FUNCTION__ << endl;
    char *cmd = "sleep 5";
    char *exec = "sh -c ";
    // string cmd_str =string(exec) + string(cmd);
    string cmd_str = string(cmd);
    cout << __fname << " Executing: " << cmd_str << endl;
    system(cmd_str.c_str());
    cout << __fname << " Done  Executing: " << cmd_str << endl;
    completed = true;
    callback_fn(1);
    return;

}

bool Non_blocking_system::canDoSomeOperation()
{
    cout << __PRETTY_FUNCTION__ << endl;
    bool res = false;

    return false;
}

void Non_blocking_system::onSomeOperationFinished(int status)
{
        cout << __PRETTY_FUNCTION__ << status << endl;
}

int main()
{
    Non_blocking_system nblk;
    completed = false;
    thread t1(Non_blocking_system::someOperation, Non_blocking_system::onSomeOperationFinished);
    cout << "Waiting for the thread to complete.\n";

    while (t1.joinable())
    {
        cout << __fname << " " << t1.get_id() << " " << std::boolalpha << t1.joinable() << endl;
        sleep(1);
        if (completed) break;
    }
    
    t1.join();

    return 0;   
}