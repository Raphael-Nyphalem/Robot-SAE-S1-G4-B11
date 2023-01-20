/* File: moteur.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *
 */

#include "moteur.hpp"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // system_clock, seconds, milliseconds


namespace saeS1{



    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Début sous-programmes
    void init_gpio_moteur()
    {
        pwmInit(CHAN_MOT_DROIT);
        pwmPeriod(CHAN_MOT_DROIT, PERIODE_MS);
        pwmDutyCycle(CHAN_MOT_DROIT,0);
        pwmEnable(CHAN_MOT_DROIT);

        pwmInit(CHAN_MOT_GAUCHE);
        pwmPeriod(CHAN_MOT_GAUCHE, PERIODE_MS);
        pwmDutyCycle(CHAN_MOT_GAUCHE,0);
        pwmEnable(CHAN_MOT_GAUCHE);
    }

    void avance_Vitesse_Droit(unsigned int vit)
    {
        /*
        gere les impulsions de commande du moteur Gauche 
        en fonction d'une puissance en % (0 a 100)
            gpio raspberry
        */
        unsigned int puissance;
        if (vit <0)
        {
            puissance = 0;
        }
        else if (vit>100)
        {
            puissance =100;
        }
        else
        {
            puissance = vit;
        }

        pwmDutyCycle(CHAN_MOT_GAUCHE,puissance);

    }

    void avance_Vitesse_Gauche(unsigned int vit)
    {
        /*
        gere les impulsions de commande du moteur Droit 
        en fonction d'une puissance en % (0 a 100)
        utilise
            gpio raspberry
        */
        unsigned int puissance;
        if (vit <0)
        {
            puissance = 0;
        }
        else if (vit>100)
        {
            puissance =100;
        }
        else
        {
            puissance = vit;
        }
        
        pwmDutyCycle(CHAN_MOT_DROIT,puissance);

    }

    void avance_vit(unsigned int vit)
    {
        /*
        utilise
            - avance_Vitesse_Droit
            - avance_Vitesse_Gauche
            - detect_angle
            - correction_angle
        */
        avance_Vitesse_Droit(vit);
        avance_Vitesse_Gauche(vit);
    
    }

    void stop_Mot_Gauche()
    {
        /*
        arret du moteur Gauche
        utilise 
            - gestion_mot_Gauche
        */
        pwmDutyCycle(CHAN_MOT_GAUCHE,0);
    }

    void stop_Mot_Droit()
    {
        /*
        arret du moteur Gauche
        utilise 
            - gestion_mot_Gauche
        */
        pwmDutyCycle(CHAN_MOT_DROIT,0);
    }

    void stop()
    {
        /*
        Permet d'arreter le robot
        utilise 
            - stop_Mot_Droit 
            - stop_Mot_Gauche
        */
        stop_Mot_Droit();
        stop_Mot_Gauche();
    }

    int main() {
        return EXIT_SUCCESS;
    }

}