//traject.hpp
#ifndef SAES1_TRAJECT_HPP
#define SAES1_TRAJECT_HPP



namespace saeS1{
    const int MAX_FONCTIONS_TRAJET = 15;
    const int MAX_PARAMETRE_TRAJET = 5;
    void copieTab(double trajet[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET], double copy[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET]);

    void base_chargement(double trajet[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET]);

    void chargement_base(double trajet[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET]);

    void chargement_A(double trajet[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET]);

    void chargement_B(double trajet[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET]);

    void A_chargement(double trajet[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET]);

    void B_chargement(double trajet[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET]);
    /*
    void A_base(double trajet[MAX_FONCTIONS][MAX_PARAMETRE]);

    void B_base(double trajet[MAX_FONCTIONS][MAX_PARAMETRE]);
    */

}//namespace saeS1

#endif //TRAJECT.HPP