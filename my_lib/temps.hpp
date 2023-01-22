//temps.hpp
#ifndef SAES1_TEMPS_HPP
#define SAES1_TEMPS_HPP

#include <iostream>
#include <ctime>
#include <chrono>

namespace saeS1{
void get_temps(std::chrono::steady_clock::time_point &temps);

bool detect_temps(
    double diff,
    std::chrono::steady_clock::time_point &tempsAVerifier);


} //namespace saeS1

#endif //TEMPS.HPP