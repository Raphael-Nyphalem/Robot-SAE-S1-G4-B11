//temps.hpp
#ifndef SAES1_TEMPS_HPP
#define SAES1_TEMPS_HPP


#include <chrono>

#include "moteur.hpp"
#include "boussole.hpp"
#include "capteur.hpp"

namespace saeS1{

    void correction_angle
    (
        double angle_cap
    );

    void avance_Cap
    (
        double cap
    );

    void avance_valon
    (
        unsigned int vit
    );

} //namespace saeS1

#endif //TEMPS.HPP