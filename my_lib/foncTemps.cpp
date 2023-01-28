/* File: foncTemps.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *
 */

#include "foncTemps.hpp"

using namespace std;
using namespace std::chrono;

namespace saeS1{

    void get_temps(temps_t &temps)
    {
        /*
        Recupère l'heure de la machine.
        Utilise :
            <chrono>
        */
        temps.t = steady_clock::now();
    }

    double temps_Passe(temps_t &temps0)
    {
        /*
       Calcule la différence de temps entre un temps0 et le temps actuel de la machine.
       Utilise :
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
        Détecte lorsque la différence de temps (entre un temps0 et le temps actuel de la machine) 
        est supérieur à un seuil.
        Renvoie vrai lorsque ce temps est supérieur au seuil.
        Utilise :
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
        return false;
    }



} //namespace saeS1
