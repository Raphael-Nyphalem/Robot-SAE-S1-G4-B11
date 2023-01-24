#include <iostream>
#include <chrono>
#include <thread>

#include "../my_lib/foncTemps.hpp"

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;
using namespace saeS1;

int main()
{
   temps_t temps0;
   get_temps(temps0);
   do
   {
    sleep_for(milliseconds(10));
    cout<<"\ndans la boucle: "<<temps_Passe(temps0);
   } while (!(detect_temps(1.05,temps0)));
   cout<<"\nor de la boucle\n";

}