/* File: capteur.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *Ce programme à pour but de permettre les test des fonctions ddes capteur de ligne
 */

#include "capteur.hpp"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // system_clock, seconds, milliseconds


namespace saeS1{
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Début constantes
    const unsigned int PIN_CAPT_GAUCHE = 16;
    const unsigned int PIN_CAPT_DROIT= 17;
    // Fin constantes
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    // Début sous-programmes
    void init_gpio_capteur()
    {
        gpioSetConfig(PIN_CAPT_GAUCHE, in);
        gpioSetConfig(PIN_CAPT_DROIT, in);
    }


    //F2 Détection des capteurs
    bool detec_Capt_Droit()
    {
        /*
        Renvois Vrais si le capteur Droit detecte une bande noir
        utilise
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
        Renvois Vrais si le capteur Gauche detecte une bande noir
        utilise
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
        Renvois Vrais si les 2 capteurs detecte une bande noir
        utilise
            - detec_Capt_Gauche
            - detec_Capt_Droit
        */
        bool detect;
        detect = detec_Capt_Droit() && detec_Capt_Gauche();
        return detect;
    }

}//namespace saeS1