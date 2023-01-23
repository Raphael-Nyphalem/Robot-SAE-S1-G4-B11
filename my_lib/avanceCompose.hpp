//avanceCompose.hpp
#ifndef SAES1_TEMPS_HPP
#define SAES1_TEMPS_HPP

#include "moteur.hpp"
#include "boussole.hpp"
#include "capteur.hpp"
#include "temps.hpp"

namespace saeS1{

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
        unsigned int vit
    );

    bool avance_temps_cap(
        double temps, 
        double cap, 
        temps_t temps0)
    };
    

} //namespace saeS1

#endif //TEMPS.HPP