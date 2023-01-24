
#include<iostream>


const int MAX_FONCTIONS = 20;
const int MAX_PARAMETRE = 6;

using namespace std;
void param_avance_valon(double tabParametre[MAX_PARAMETRE])
{
    double cap;
    tabParametre[0]=1;
    cout << "Entrez un cap (metre -1 pour cet a le cap tout droit) " <<endl;
    cin>>cap;
    tabParametre[2]=cap;

}

void param_avance_temps_cap(double tabParametre[MAX_PARAMETRE])
{
    double temps, cap;
    tabParametre[0]=2;
    cout << "Entrez les paramètres de temps et de cap (metre -1 pour cet a le cap tout droit) : " <<endl;
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

void param_demit_tours(double tabParametre[MAX_PARAMETRE])
{
    double angle;
    tabParametre[0]=4;

}

void init_tab_0(double tabRobot[MAX_FONCTIONS][MAX_PARAMETRE])
    {
        for (int f = 0; f < MAX_FONCTIONS; f++)
        {
            for (int p = 0; p < MAX_PARAMETRE; p++)
            {
                tabRobot[f][p]=0;
            } 
        }
    }

void create_etape(double tabParametre[MAX_PARAMETRE])
{
    double fonction;
    int fonction_int;

    cout<<"donnez fonction a utiliser\n"
        <<"0 pour stop\n"
        <<"1 pour avance valon\n"
        <<"2 pour avance temps cap\n"
        <<"3 pour tourne cap\n";
        <<"4 pour demit tour\n";

    cin>> fonction;
    fonction_int = fonction;

    tabParametre[1]=1;

    switch (fonction_int)
    {
    case 0:
        break;
    
    case 1:
        param_avance_valon(tabParametre);
        break;

    case 2:
        param_avance_temps_cap(tabParametre);
        break;

    case 3:
        param_tourne_cap(tabParametre);
        break;
    case 4:
        param_demit_tours(tabParametre);
        break;
    
    default:
        break;
    }
}

void cree_tab(double tabParametre[MAX_FONCTIONS][MAX_PARAMETRE])
{
    for (int i = 0; i < MAX_FONCTIONS; i++)
    {
        cout<<" codage étape "<<i<<endl;
        create_etape(tabParametre[i]);
    }   
}

void affiche_tab(double tabParametre[MAX_FONCTIONS][MAX_PARAMETRE])
{
    cout<<"{";
    for (int f = 0; f < MAX_FONCTIONS; f++)
    {
        cout<<"{";
        for (int p = 0; p < MAX_PARAMETRE; p++)
        {
            cout << tabParametre[f][p];
            if (p<(MAX_PARAMETRE-1))
            {
                cout<<",";
            }
            
        }
        cout<<"}";
        if (f<(MAX_FONCTIONS-1))
            {
                cout<<",";
            }
    }
    cout<<"}\n";
}

int main(int argc, char const *argv[])
{
    double trajet[MAX_FONCTIONS][MAX_PARAMETRE];
    init_tab_0(trajet);
    cree_tab(trajet);
    affiche_tab(trajet);
    return 0;
}
