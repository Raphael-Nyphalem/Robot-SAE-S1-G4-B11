//avanceCompose.hpp
#ifndef SAES1_AVANCECOMPOSE_HPP
#define SAES1_AVANCECOMPOSE_HPP

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <string>

#include "moteur.hpp"
#include "boussole.hpp"
#include "capteur.hpp"
#include "foncTemps.hpp"

namespace saeS1{
    
    void init();

    void correction_angle
    (
        double angle_cap
    );

    void avance_Cap
    (
        double cap
    );

    bool avance_valon
    (
        double cap
    );

    bool avance_temps_cap
    (
        double temps, 
        double cap, 
        temps_t temps0
    );

    bool tourne_cap
    (
        double angle_tourne
    );
    

} //namespace saeS1

#endif //AVANCECOMPOSE.HPP