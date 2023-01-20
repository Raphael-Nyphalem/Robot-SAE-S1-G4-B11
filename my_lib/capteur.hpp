//capteur.hpp
#ifndef SAES1CAPTEUR_HPP
#define SAES1CAPTEUR_HPP

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include <sensehat.h>

namespace saeS1{

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