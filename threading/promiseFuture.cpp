#include <thread>
#include <future>
#include <mutex>
#include <iostream>

using namespace std;

mutex m;
void ThreadFunc(promise<int>& prom)
{
    std::lock_guard<mutex> lock(m);
    cout << __PRETTY_FUNCTION__ << endl;
    prom.set_value(12);
    this_thread::sleep_for(chrono::seconds(2));
    cout << __PRETTY_FUNCTION__ << endl;
}
int main(int argc, char const *argv[])
{
    promise<int> myPromise;
    // future<void> myfuture = async(std::launch::async, ThreadFunc, ref(myPromise));
    future<int> myfuture = myPromise.get_future();
    thread t1(ThreadFunc, ref(myPromise));

    cout <<  __PRETTY_FUNCTION__ << endl;
    myfuture.get();
    t1.join();

    return 0;
}
