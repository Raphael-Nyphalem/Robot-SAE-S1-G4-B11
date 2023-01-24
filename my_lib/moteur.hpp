#ifndef SAES1_MOTEUR_HPP
#define SAES1_MOTEUR_HPP



#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <string>
#include <sensehat.h>


namespace saeS1{

    const unsigned int CHAN_MOT_GAUCHE = 0;
    const unsigned int CHAN_MOT_DROIT= 1;
    const unsigned int PERIODE_MS = 10000;


    const int VITESSE_0 = 0;
    const int VITESSE_1 = 25;
    const int VITESSE_2 = 50;
    const int VITESSE_3 = 75;
    const int VITESSE_4 = 100;
    const int VITESSE_ROBOT = 100;

    void 
    init_gpio_moteur();

 
    void 
    avance_Vitesse_Droit(
            unsigned int vit
            );

    void 
    avance_Vitesse_Gauche(
            unsigned int vit
            );

    void 
    avance_vit(
            unsigned int vit
            );

    void 
    stop_Mot_Gauche();

    void 
    stop_Mot_Droit();

    void 
    stop();

} //namespace saeS1

#endif // MOTEUR_HPP