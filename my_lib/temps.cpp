/* File: temps.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *
 */

#include "temps.hpp"

using namespace std::chrono;

namespace saeS1{

    void get_temps(temps_t &temps)
    {
        /*
        Recupère l'heure de la machine
        utilise
            <chrono>
        */
        temps.t = steady_clock::now();
    }

    double temps_Passe(temps_t &temps0)
    {
        /*
        calcul la difference de temps entre un temps0 et le temps actuel de la machine
        utilise
            <chrono>
            get_temps
        */
        temps_t tempsActuel;
        get_temps(tempsActuel);

        duration<double> temps_diff = duration_cast<duration<double>>(tempsActuel.t-temps0.t);
        return temps_diff.count();
    }

    bool detect_temps(double tempsSeuil,temps_t &temps0)
    {
        /*
        Detecte lorsque la difference de temps (entre un temps0 et le temps actuel de la machine) 
        est supperieur a un seuil
        utilise
            temps_Passe
        */
        if (temps_Passe(temps0) >= tempsSeuil)
        {
            return true;
        }
        else
        {
            return false;
        }
    }



} //namespace saeS1