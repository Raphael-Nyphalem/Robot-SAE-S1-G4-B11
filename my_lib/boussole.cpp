/* File: tp8-ex1.cpp
 * Author: Philippe Latu
 * Source: https://github.com/platu/libsensehat-cpp
 *
 * Patron du code source des séances de travaux pratiques
 */


#include "boussole.hpp"
using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;	  // system_clock, seconds, milliseconds


namespace saeS1{

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Début constantes

    // Fin constantes
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    void init_Compas()
    {
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
        return senseGetCompass();
    }

    bool calcul_Min_Max (double &min,double &max,double cap)
    {
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

    bool detect_angle(double cap)
    {
        double angle;
        double min,max;
        double save_val;

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