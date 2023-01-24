//temps.hpp
#ifndef SAES1_FONCTEMPS_HPP
#define SAES1_FONCTEMPS_HPP

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <string>

namespace saeS1{

    typedef struct temps_t{
        std::chrono::steady_clock::time_point t;
    }temps_t;

    void get_temps(
        temps_t &temps
        );

    double temps_Passe(
        temps_t &temps0
        );

    bool detect_temps(
        double tempsSeuil,
        temps_t &temps0);

} //namespace saeS1

#endif //FONCTEMPS_HPP