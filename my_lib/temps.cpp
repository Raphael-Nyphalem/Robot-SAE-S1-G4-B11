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

    void get_temps(temps_t &temps)
    {
        temps.t = steady_clock::now();
    }

    bool detect_temps(double diff,temps_t &tempsAVerifier)
    {
        temps_t tempsActuel;
        get_temps(tempsActuel);

        duration<double> time_span = duration_cast<duration<double>>(tempsActuel.t-tempsAVerifier.t);
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