//robot.hpp
#ifndef SAES1_ROBOT_HPP
#define SAES1_ROBOT_HPP

#include <iostream>
#include "my_lib/avanceCompose.hpp"

#include "my_lib/boussole.hpp"
#include "my_lib/capteur.hpp"
#include "my_lib/moteur.hpp"
#include "my_lib/temps.hpp"

namespace saeS1{
    const int MAX_FONCTIONS = 30;
    const int MAX_PARAMETRE = 6;

    
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

    void edit_etape
    (
        double tabParametre[MAX_PARAMETRE]
    );

    void copie_etape
    (
        double tabParametre[MAX_PARAMETRE],
        double tabACopier[MAX_PARAMETRE]
    );

    void affiche_etape
    (
        double tabParametre[MAX_PARAMETRE]
    );

    void init_tab_0
    (
        double tabRobot[MAX_FONCTIONS][MAX_PARAMETRE]
    );


} //namespace saeS1

#endif //SAES1_ROBOT_HPP