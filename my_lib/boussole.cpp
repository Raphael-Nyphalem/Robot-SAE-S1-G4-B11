/* File: boussole.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *
 */


#include "boussole.hpp"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;	  // system_clock, seconds, milliseconds


namespace saeS1{

    void init_Compas()
    {
        /*
        Permet d'initialiser la boussole.
        Utilise :
        <sensehat.h>
        get_compas()
        */
        int cpt;
        senseSetIMUConfig(true, true, true);
        for (cpt = 0; cpt < INT_MESURES; cpt++)
        {
            senseGetCompass();
        }
        cout << "initialisation faite" << endl;
    }

    double get_compas()
    {
        /*
        Permet d'obtenir l'angle actuel de la boussole.
        Utilise :
        <sensehat.h>
        */
        return senseGetCompass();
    }

    bool calcul_Min_Max (double &min,double &max,double cap)
    {
        /*
        Permet de calculer une plage autour du cap a suivre MIN, MAX.
        Prend en compte lorsque le cap est proche de 0 grâce à la varible inverse.
        Renvoie vrai lorsqu'on est dans le cas inverse.
        */
        double save_val;
        bool inverse = false;

        min = cap - DEGRE_ANGLE_LIB;
        max = cap + DEGRE_ANGLE_LIB;
        save_val = max;

        if(min < 0)
        {
            max = 360 + min;
            min = save_val;
            inverse = true;
        }
        else if(max > 360)
        {
            max = max - 360;
            min = save_val;
            inverse = true;
        }
        return inverse;
    }

    bool calcul_Inverse_Cap(double cap, double &nonCap)
    {
        /*
            Permet de calculer l'angle opposé au cap.
            Renvoie vrai si le cap est supérieur à 180 et calcule l'opposé du cap.
        */
        if(cap < 180)
        {
            nonCap = cap+180;
            return false;
        }
        else
        {
            nonCap = cap-180;
            return true;
        }
    }

    double calcul_Nouveau_Cap(double direction)
    {
        double cap = get_compas();

        double nouveauCap;

        if((cap + direction)<0)
        {
            nouveauCap = cap + direction + 360;
        }
        else if ((cap + direction)>360)
        {
            nouveauCap = cap + direction - 360;
        }
        else
        {
           nouveauCap = cap + direction;
        }
        return nouveauCap;
        
    }

    bool detect_angle(double cap)
    {
        /*
        Permet de détecter si le sensor (ou le robot dans notre cas)
        est dans le cap .
        Utilise :
        get_compas()
        calcul_Min_Max()

        */
        double angle;
        double min,max;

        angle = get_compas();


        if (calcul_Min_Max(min,max,cap))
        {
            if (!(angle >= min && angle <= max))
            {
                return true;
            }
        }
        else
        {
            if (angle >= min && angle <= max)
            {
                return true;
            }
        }
        return false;
        
    }
}//namespace saeS1
