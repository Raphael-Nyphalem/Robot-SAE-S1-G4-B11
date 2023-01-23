
#include<iostream>
#include "my_lib/robot.hpp"


using namespace std;
using namespace saeS1;

void param_avance_valon(double tabParametre[MAX_PARAMETRE])
{
    tabParametre[0]=1;

}

void param_avance_temps_cap(double tabParametre[MAX_PARAMETRE])
{
    double temps, cap;
    tabParametre[0]=2;
    cout << "Entrez les paramètres de temps et de cap : " <<endl;
    cin >> temps;
    cin >> cap;

    tabParametre[2]=temps;
    tabParametre[3] = cap;
}

void param_tourne_cap(double tabParametre[MAX_PARAMETRE])
{
    double angle;
    tabParametre[0]=3;
    cout << "Entrez l'angle pour tourner (entre -170° et +170°) : " << endl;
    cin >> angle;
    tabParametre[2] = angle;

}



void create_etape(double tabParametre[MAX_PARAMETRE])
{
    double fonction;
    int fonction_int;
        
    bool avance_temps_cap(double temps, double cap, tem
    cout<<"donnez fonction a utiliser\n"
        <<"0 pour stop\n"
        <<"1 pour avance valon\n"
        <<"2 pour avance temps cap\n"
        <<"3 pour tourne cap\n";

    cin>> fonction;
    fonction_int = fonction;

    tabParametre[1]=1;

    switch (fonction_int)
    {
    case 0:
        break;
    
    case 1:

        break;
    
    default:
        break;
    }


}


int main(int argc, char const *argv[])
{
    double trajet[MAX_FONCTIONS][MAX_PARAMETRE]
    init_tab_0(trajet);
    


    return 0;
}
