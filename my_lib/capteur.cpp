/* File: capteur.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *
 */

#include "capteur.hpp"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // system_clock, seconds, milliseconds


namespace saeS1{



    // Début sous-programmes
    void init_gpio_capteur()
    {
        /*
        Permet d'initialiser les pins des capteurs gpios.
        Utilise :
        gpio rapsberry
        */
        gpioSetConfig(PIN_CAPT_GAUCHE, in);
        gpioSetConfig(PIN_CAPT_DROIT, in);
    }


    //F2 Détection des capteurs
    bool detec_Capt_Droit()
    {
        /*
        Renvoie vrai si le capteur droit détecte une bande noire.
        Utilise :
            gpio raspberry
        */
        bool detect;
        detect= false;
        if (gpioGetInput(PIN_CAPT_DROIT) ==0)
        {
        detect = true;
        }
        return detect;
    }

    bool detec_Capt_Gauche()
    {
        /*
        Renvoie vrai si le capteur gauche détecte une bande noire.
        Utilise :
            gpio raspberry
        */
        bool detect;
        detect= false;
        if (gpioGetInput(PIN_CAPT_GAUCHE) == 0)
        {
        detect = true;
        }
        return detect;
    }

    bool detec_2_Capt()
    {
        /*
        Renvoie vrai si les 2 capteurs détectent une bande noire.
        Utilise :
            - detec_Capt_Gauche
            - detec_Capt_Droit
        */
        bool detect;
        detect = detec_Capt_Droit() && detec_Capt_Gauche();
        return detect;
    }

}//namespace saeS1
