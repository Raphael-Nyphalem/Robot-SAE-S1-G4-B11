//boussole.hpp
#ifndef SAES1_BOUSSOLE_HPP
#define SAES1_BOUSSOLE_HPP


#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <string>

#include <sensehat.h>

namespace saeS1{

    const int INT_MESURES = 100;
    const int DEGRE_ANGLE_LIB = 10;

    void init_Compas();

    double get_compas();

    bool calcul_Min_Max 
    (
        double &min,
        double &max,
        double cap
    );

    bool detect_angle
    (
        double cap
    );
    
    bool calcul_Inverse_Cap
    (
        double cap,
        double &nonCap
    );

    double calcul_Nouveau_Cap
    (
        double direction
    );

} //namespace saeS1

#endif //BOUSSOLE_HPP