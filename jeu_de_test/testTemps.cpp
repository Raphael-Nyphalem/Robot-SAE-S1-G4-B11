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
      cout<<"\ndans la boucle: "<<temps_Passe(temps0)<<endl;
      sleep_for(milliseconds(100));
   } while (!(detect_temps(1.05,temps0)));
   cout<<"\nhors de la boucle "<<temps_Passe(temps0)<<endl;

}
