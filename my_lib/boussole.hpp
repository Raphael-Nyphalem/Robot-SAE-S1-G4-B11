//boussole.hpp
#ifndef BOUSSOLE_HPP
#define BOUSSOLE_HPP

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <string>
#include <sensehat.h>

namespace saeS1{

    void init_Compas();

    double get_compas();

    bool calcul_Min_Max (
        double &min,
        double &max,
        double cap
        );

    bool detect_angle(
        double cap
        );

} //namespace saeS1

#endif //CAPTEUR_HPP