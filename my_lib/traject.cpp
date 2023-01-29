/* File: traject.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 */
#include "traject.hpp"
namespace saeS1{

    void copieTab(double trajet[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET], double copy[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET])
    {
        //Cette fonction permet de copier le tableau “copy” dans le tableau “trajet”.
        for (int f = 0; f < MAX_FONCTIONS_TRAJET; f++)
        {
            for (int p = 0; p < MAX_PARAMETRE_TRAJET; p++)
            {
                trajet[f][p]=copy[f][p];
            }
        }
    }

    void base_chargement(double trajet[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET])
    {
        /*
        Décrit le chemin de la base du robot pour recharger sa batterie a la zone de chargement de la marchandise
        */
       double BC[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET]= {
           {2,1,1,-1,0},{1,1,-1,0,0},{3,1,90,0,0},{1,1,-1,0,0},{4,1,0,0,0},
           {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
           {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};

       copieTab(trajet,BC);

    }
    void chargement_base(double trajet[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET])
    {
        /*
        Décrit le chemin de la la zone de chargement de la marchandise vers base du robot pour recharger sa batterie
        */
       double CB[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET]= {
        {0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
       copieTab(trajet,CB);
    }

    void chargement_A(double trajet[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET])
    {
        /*
        Décrit le chemin de la zone de chargement de la marchandise au point A
        */
       double CA[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET]= {
        {0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
       copieTab(trajet,CA);
    }

    void chargement_B(double trajet[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET])
    {
        /*
        Décrit le chemin de la zone de chargement de la marchandise au point B
        */
       double CB[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET]= {
        {0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
       copieTab(trajet,CB);
    }

    void A_chargement(double trajet[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET])
    {
        /*
        Décrit le chemin du point A j'usqu'a la zone de chargement de la marchandise 
        */
       double AC[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET]= {
        {0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
       copieTab(trajet,AC);
    }

    void B_chargement(double trajet[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET])
    {
        /*
        Décrit le chemin du point B j'usqu'a la zone de chargement de la marchandise 
        */
       double BC[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET]= {
        {0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
       copieTab(trajet,BC);
    }

    /*
    void A_base(double trajet[MAX_FONCTIONS][MAX_PARAMETRE])
    {
        
        //Décrit le chemin du point A j'usqu'a la base 
        
       //double AB[MAX_FONCTIONS][MAX_PARAMETRE]= 
       //copieTab(trajet,AB);
    }

    void B_base(double trajet[MAX_FONCTIONS][MAX_PARAMETRE])
    {
        
        //Décrit le chemin du point B j'usqu'a la base 
        
       //double BB[MAX_FONCTIONS][MAX_PARAMETRE]= 
       //copieTab(trajet,BB);
    }
    */

}//namespace