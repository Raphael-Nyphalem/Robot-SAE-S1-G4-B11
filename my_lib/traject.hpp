//traject.hpp
#ifndef SAES1_TRAJECT_HPP
#define SAES1_TRAJECT_HPP

#include "robot.hpp"

namespace saeS1{
    void copieTab(double trajet[MAX_FONCTIONS][MAX_PARAMETRE],double copy[MAX_FONCTIONS][MAX_PARAMETRE]);

    void base_chargement(double trajet[MAX_FONCTIONS][MAX_PARAMETRE]);

    void chargement_base(double trajet[MAX_FONCTIONS][MAX_PARAMETRE]);

    void chargement_A(double trajet[MAX_FONCTIONS][MAX_PARAMETRE]);

    void chargement_B(double trajet[MAX_FONCTIONS][MAX_PARAMETRE]);

    void A_chargement(double trajet[MAX_FONCTIONS][MAX_PARAMETRE]);

    void B_chargement(double trajet[MAX_FONCTIONS][MAX_PARAMETRE]);
    /*
    void A_base(double trajet[MAX_FONCTIONS][MAX_PARAMETRE]);

    void B_base(double trajet[MAX_FONCTIONS][MAX_PARAMETRE]);
    */

}//namespace saeS1

#endif //TRAJECT.HPP