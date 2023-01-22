/* File: capteur.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *
 */

#include "temps.hpp"

using namespace std;
using namespace std::chrono;

namespace saeS1{

    void get_temps(steady_clock::time_point &temps)
    {
        temps = steady_clock::now();
    }

    bool detect_temps(double diff,steady_clock::time_point &tempsAVerifier)
    {
        steady_clock::time_point tempsActuel;
        get_temps(tempsActuel);

        duration<double> time_span = duration_cast<duration<double>>(tempsActuel-tempsAVerifier);
        if (time_span.count() >= diff)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
    }

} //namespace saeS1