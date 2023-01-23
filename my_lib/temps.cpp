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

    double temps_Passe(temps_t &temps0)
    {
        temps_t tempsActuel;
        get_temps(tempsActuel);

        duration<double> temps_diff = duration_cast<duration<double>>(tempsActuel.t-temps0.t);
        return temps_diff.count();
    }

    bool detect_temps(double diff,temps_t &temps0)
    {
        if (temps_Passe(temps0) >= diff)
        {
            return true;
        }
        else
        {
            return false;
        }
    }



} //namespace saeS1