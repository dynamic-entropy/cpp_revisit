#include <iostream>
#include <thread>

using namespace std;

void func()
{
    cout << "T1:: Hello World!!\n";
}

class functor
{
public:
    void operator()()
    {
        cout << "Thread:: Hello from functor" << endl;
    }
};

int main()
{
    thread t1(func);
    cout << "Main :: Hello World!\n";
    cout << "Main::ThreadId =   " << this_thread::get_id() << endl;
    cout << "T1::ThreadId =  " << t1.get_id() << endl;

    //thread t2 = t1; Not allowed since Threads cannot be copied
    //thread t3(functor()); Not allowed since it matches a function declaration,
    cout << "Number of thread contexts =  " << thread::hardware_concurrency() << endl;

    thread t3((functor()));
    t3.join();
    thread t2 = move(t1);
    // t1.join();
    // t1.detach();
    try
    {
        // int i=1000000; while(i--);
        cout << "Main:: Hello again World!\n";
    }
    catch (...)
    {
        t2.join();
        throw;
    }
    if (t2.joinable())
        t2.join();
}