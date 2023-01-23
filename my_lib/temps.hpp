//temps.hpp
#ifndef SAES1_TEMPS_HPP
#define SAES1_TEMPS_HPP

#include <iostream>
#include <ctime>
#include <chrono>

namespace saeS1{

    typedef struct{
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

#endif //TEMPS.HPP