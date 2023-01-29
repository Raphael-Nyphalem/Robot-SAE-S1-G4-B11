#include <iostream>
#include <chrono>
#include <thread>

#include "../my_lib/traject.hpp"

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;
using namespace saeS1;

void affiche_tab(double tabParametre[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET])
{
    cout<<"{";
    for (int f = 0; f < MAX_FONCTIONS_TRAJET; f++)
    {
        cout<<"{";
        for (int p = 0; p < MAX_PARAMETRE_TRAJET; p++)
        {
            cout << tabParametre[f][p];
            if (p<(MAX_PARAMETRE_TRAJET-1))
            {
                cout<<",";
            }
            
        }
        cout<<"}";
        if (f<(MAX_FONCTIONS_TRAJET-1))
            {
                cout<<",";
            }
    }
    cout<<"}\n";
}

void testCopie()
{
    double tab1[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET] = {
        {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
        {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
        {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    
    double tab2[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET] = {
        {2,1,1,-1,0},{1,1,-1,0,0},{3,1,90,0,0},{1,1,-1,0,0},{4,1,0,0,0},
        {2,1,1,-1,0},{1,1,-1,0,0},{3,1,90,0,0},{1,1,-1,0,0},{4,1,0,0,0},
        {2,1,1,-1,0},{1,1,-1,0,0},{3,1,90,0,0},{1,1,-1,0,0},{4,1,0,0,0}};

    cout<<"\taffichage tab1\n";
    affiche_tab(tab1);
    cout<<"\taffichage tab2\n";
    affiche_tab(tab2);

    cout<<"\n\t copie de tab2 dans tab1 \n";
    copieTab(tab1,tab2);

    cout<<"\taffichage tab1\n";
    affiche_tab(tab1);
    cout<<"\taffichage tab2\n";
    affiche_tab(tab2);
}

void test_trajets()
{
    double tab1[MAX_FONCTIONS_TRAJET][MAX_PARAMETRE_TRAJET]= {
        {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
        {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},
        {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    
    cout<<"\taffichage tab1\n";
    affiche_tab(tab1);


    cout<<"\n\t fonction base_chargement(tab1) \n ";
    base_chargement(tab1);
    cout<<"\taffichage tab1\n";
    affiche_tab(tab1);

    cout<<"\n\t fonction chargement_base(tab1) \n ";
    chargement_base(tab1);
    cout<<"\taffichage tab1\n";
    affiche_tab(tab1);

    cout<<"\n\t fonction chargement_A(tab1) \n ";
    chargement_A(tab1);
    cout<<"\taffichage tab1\n";
    affiche_tab(tab1);

    cout<<"\n\t fonction chargement_B(tab1) \n ";
    chargement_B(tab1);
    cout<<"\taffichage tab1\n";
    affiche_tab(tab1);

    cout<<"\n\t fonction A_chargement(tab1) \n ";
    A_chargement(tab1);
    cout<<"\taffichage tab1\n";
    affiche_tab(tab1);

    cout<<"\n\t fonction B_chargement(tab1) \n ";
    B_chargement(tab1);
    cout<<"\taffichage tab1\n";
    affiche_tab(tab1);
}

int main(int argc, char const *argv[])
{
    int debuter;
        bool exitboucle = true;
        do
        {
            cout <<"Pour démarrer le robot merci de rentrer le scénario choisi : " << endl << "\t" 
                << "0 pour stop le programme"<< endl << "\t" 
                << "1 pour le test de la copie"<< endl<<"\t"
                << "2 pour les tests des fonction de chargement"<< endl;
            cin>> debuter;        
            
            //selectionneur de scénario (mode)
            
            switch (debuter) {
                case 0:
                    exitboucle=false;
                    break;
                case 1 :
                    testCopie();
                    break;
                case 2:
                    test_trajets();
                    break;
                default:
                    break;
            }
        }while(exitboucle);
}
