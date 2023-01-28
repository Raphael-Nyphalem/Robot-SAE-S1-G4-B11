/* File: moteur.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *
 */

#include "moteur.hpp"

namespace saeS1{



    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Début sous-programmes
    void init_gpio_moteur()
    {
        /*
        Permet d'initialiser 
        les channel des moteurs.
        Leur applique une période.
        Stop les moteur a l'init.
        Utilise :
        gpio rapsberry
        */
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
        Gère les impulsions de commande du moteur Gauche 
        en fonction d'une puissance en % (0 a 100).
        Utilise :
            gpio raspberry
        */
        unsigned int puissance;
        if (vit>100)
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
        Gère les impulsions de commande du moteur Droit 
        en fonction d'une puissance en % (0 a 100).
        Utilise :
            gpio raspberry
        */
        unsigned int puissance;
        if (vit>100)
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
        Utilise :
            - avance_Vitesse_Droit
            - avance_Vitesse_Gauche
        */
        avance_Vitesse_Droit(vit);
        avance_Vitesse_Gauche(vit);
    
    }

    void stop_Mot_Gauche()
    {
        /*
        Arrêt du moteur Gauche.
        Utilise :
            gpio raspberry
        */
        pwmDutyCycle(CHAN_MOT_GAUCHE,0);
    }

    void stop_Mot_Droit()
    {
        /*
        Arrêt du moteur Droit.
        Utilise :
            gpio raspberry
        */
        pwmDutyCycle(CHAN_MOT_DROIT,0);
    }

    void stop()
    {
        /*
        Permet d'arrêter le robot.
        Utilise :
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
