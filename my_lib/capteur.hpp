//capteur.hpp
#ifndef SAES1CAPTEUR_HPP
#define SAES1CAPTEUR_HPP


#include <sensehat.h>

namespace saeS1{

    const unsigned int PIN_CAPT_GAUCHE = 16;
    const unsigned int PIN_CAPT_DROIT= 17;
    
    void 
    init_gpio_capteur();

    bool 
    detec_Capt_Droit();

    bool 
    detec_Capt_Gauche();

    bool 
    detec_2_Capt();

} //namespace saeS1

#endif //CAPTEUR_HPP