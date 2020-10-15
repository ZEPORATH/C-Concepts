#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <condition_variable>
#include <chrono>

using namespace std;
using namespace chrono;
std::condition_variable producer;
std::condition_variable consumer;
bool exitLoop = false;

class SharedMem{
public:
    SharedMem () {_count = 0;}
    void increaseCount(int i);
    int removeCount();
private:
    int _count;
    std::mutex _countMutex;
    const int MAX_COUNT = 100;
};

class Producer {
public:
    Producer(SharedMem& m): mem(m) {}
    void addCount() 
    {
        while (exitLoop == false)
        {
            /* code */           
            mem.increaseCount(10);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        
    }
private:
SharedMem& mem;
};

class Consumer {
public:
    Consumer(SharedMem& m): mem(m) {}
    void removeCount()
    {
       while(exitLoop == false)
       {
           mem.removeCount();
           std::this_thread::sleep_for(chrono::milliseconds(10));
       }
    }
private:
SharedMem& mem;
};

void SharedMem::increaseCount(int count)
{
    cout << __PRETTY_FUNCTION__  << endl;
    // std::lock_guard<mutex> lg(_countMutex); //RAII wrapper for mutex
    std::unique_lock<mutex> lk(_countMutex);
    
    //Implement WAIT HERE
    consumer.wait(lk, [this, &count] {
        if (_count + count > MAX_COUNT)
        {
            cout << __PRETTY_FUNCTION__ << " " << std::this_thread::get_id() << " " << "Waiting for consumer" <<  _count << endl;
            return false;
        }
        return true;
        }
    );
    _count += count;
    producer.notify_all();
}

int SharedMem::removeCount()
{
    cout << __PRETTY_FUNCTION__ << endl;
    // std::lock_guard<mutex> lg(_countMutex);
    unique_lock<mutex> lk(_countMutex);
    
    //Implement WAIT HERE
    producer.wait(lk, [this] {
        if (_count - 10 < 0)
        {
            cout << __PRETTY_FUNCTION__ << " " << std::this_thread::get_id() << " " << "Waiting for producer " << _count << endl;
            return false;
        }
        return true;
        }
    );
    _count -= 10;
    consumer.notify_all(); //Notify the consumer to read/empty the memory
    return 10;
}

int main(int argc, char const *argv[])
{
    SharedMem mem;
    shared_ptr<Producer> p  = make_shared<Producer>(mem);
    // Producer* p = new Producer(mem);
    shared_ptr<Consumer> c  = make_shared<Consumer>(mem);
    thread t1 (&Producer::addCount, p);
    thread t5 (&Producer::addCount, p);
    thread t2 (&Consumer::removeCount, c);
    thread t3 (&Consumer::removeCount, c);
    thread t4 (&Consumer::removeCount, c);
    
    //Run both threads for 10 sec each 
    int N =5;
    int i=N;
    while (i--)
    {
        std::this_thread::sleep_for(chrono::seconds(1));
        cout << " Time elapsed: " << N-i << " seconds" << endl;
    }
    exitLoop = true;
    cout << "t1 thread joining id: " << t1.get_id() << endl; t1.join();
    cout << "t5 thread joining id: " << t5.get_id() << endl; t5.join();
    cout << "t2 thread joining id: " << t2.get_id() << endl; t2.join();
    cout << "t3 thread joining id: " << t3.get_id() << endl; t3.join();
    cout << "t4 thread joining id: " << t4.get_id() << endl; t4.join();
    
    return 0;
}

