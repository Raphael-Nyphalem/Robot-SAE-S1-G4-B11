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

void get_temps(temps_t &temps);

bool detect_temps(
    double diff,
    temps_t &tempsAVerifier);


} //namespace saeS1

#endif //TEMPS.HPP