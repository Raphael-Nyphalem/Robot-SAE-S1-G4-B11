
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

int main(int argc, char const *argv[])
{
    auto c =  system_clock::now();
    for (int i = 0; i < 10; i++)
    {
        cout << "\ntest\n\t";
        sleep_for(seconds(1));
        auto d = system_clock::now();
        duration<double> a = d-c;
        cout << a.count();
        if( a.count()> 4)
        {
            cout<<"\nYEAAA";
        }
    }
    
    
    
    return 0;
}
