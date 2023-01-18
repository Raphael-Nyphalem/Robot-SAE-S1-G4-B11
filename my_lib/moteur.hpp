#ifndef S1SAE_MOTEUR_HPP
#define S1SAE_MOTEUR_HPP


#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <sensehat.h>

namespace saeS1{
	
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