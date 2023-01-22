#include <iostream>
#include <chrono>
#include <thread>

#include "../my_lib/temps.hpp"


// Function to calculate
// Fibonacci series

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;
using namespace saeS1;

int main()
{
   steady_clock::time_point temps0;
   saeS1::get_temps(temps0);
   do
   {
    sleep_for(milliseconds(1000));
    cout<<"dans la boucle\n";
   } while (!(saeS1::detect_temps(10,temps0)));
   cout<<"or de la boucle\n";



}