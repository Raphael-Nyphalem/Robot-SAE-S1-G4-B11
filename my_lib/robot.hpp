//robot.hpp
#ifndef SAES1_ROBOT_HPP
#define SAES1_ROBOT_HPP

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <string>

#include "moteur.hpp"
#include "boussole.hpp"
#include "capteur.hpp"
#include "foncTemps.hpp"
#include "avanceCompose.hpp"
#include "traject.hpp"

namespace saeS1{
    const int MAX_FONCTIONS = 15;
    const int MAX_PARAMETRE = 5;

    
    void robot
    (
        double tabRobot[MAX_FONCTIONS][MAX_PARAMETRE]
    );

    void execute_stop_0
    (
        double tabParametre[MAX_PARAMETRE]
    );

    void execute_avanceValon_1
    (
        double tabParametre[MAX_PARAMETRE]
    );

    void execute_avanceTempsCap_2
    (
        double tabParametre[MAX_PARAMETRE]
    );

    void execute_tourne_cap_3
    (
        double tabParametre[MAX_PARAMETRE]
    );
    
    void execute_etape 
    (
        double tabParametre[MAX_PARAMETRE]
    );

    bool detect_etape_en_cours
    (
        double tabParametre[MAX_PARAMETRE]
    );

    /*

    void copie_etape
    (
        double tabParametre[MAX_PARAMETRE],
        double tabACopier[MAX_PARAMETRE]
    );

    void affiche_etape
    (
        double tabParametre[MAX_PARAMETRE]
    );
    */


} //namespace saeS1

#endif //SAES1_ROBOT_HPP