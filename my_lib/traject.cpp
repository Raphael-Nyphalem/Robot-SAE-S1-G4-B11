
#include "traject.hpp"
namespace saeS1{

    void copieTab(double trajet[MAX_FONCTIONS][MAX_PARAMETRE],double copy[MAX_FONCTIONS][MAX_PARAMETRE])
    {
        for (int f = 0; f < MAX_FONCTIONS; f++)
        {
            for (int p = 0; p < MAX_PARAMETRE; p++)
            {
                trajet[f][p]=copy[f][p];
            }
        }
    }

    void base_chargement(double trajet[MAX_FONCTIONS][MAX_PARAMETRE])
    {
        /*
        Décrit le chemin de la base du robot pour recharger sa batterie a la zone de chargement de la marchandise
        */
       double BC[MAX_FONCTIONS][MAX_PARAMETRE]= {
        {0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};

       copieTab(trajet,BC);

    }
    void chargement_base(double trajet[MAX_FONCTIONS][MAX_PARAMETRE])
    {
        /*
        Décrit le chemin de la la zone de chargement de la marchandise vers base du robot pour recharger sa batterie
        */
       double CB[MAX_FONCTIONS][MAX_PARAMETRE]= {
        {0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
       copieTab(trajet,CB);
    }

    void chargement_A(double trajet[MAX_FONCTIONS][MAX_PARAMETRE])
    {
        /*
        Décrit le chemin de la zone de chargement de la marchandise au point A
        */
       double CA[MAX_FONCTIONS][MAX_PARAMETRE]= {
        {0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
       copieTab(trajet,CA);
    }

    void chargement_B(double trajet[MAX_FONCTIONS][MAX_PARAMETRE])
    {
        /*
        Décrit le chemin de la zone de chargement de la marchandise au point B
        */
       double CB[MAX_FONCTIONS][MAX_PARAMETRE]= {
        {0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
       copieTab(trajet,CB);
    }

    void A_chargement(double trajet[MAX_FONCTIONS][MAX_PARAMETRE])
    {
        /*
        Décrit le chemin du point A j'usqu'a la zone de chargement de la marchandise 
        */
       double AC[MAX_FONCTIONS][MAX_PARAMETRE]= {
        {0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
       {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
       copieTab(trajet,AC);
    }

    void B_chargement(double trajet[MAX_FONCTIONS][MAX_PARAMETRE])
    {
        /*
        Décrit le chemin du point B j'usqu'a la zone de chargement de la marchandise 
        */
       double BC[MAX_FONCTIONS][MAX_PARAMETRE]= {
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