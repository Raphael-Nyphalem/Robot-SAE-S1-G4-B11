/* File: robot_.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *Ce programme à pour but de permettre le fonctionnement de la base roulante mobile selon trois différents scénarios
 *
 * Scénarios : 
 * 
 * Scénario 1 --> Suivi ligne droite
 * 
 * Scénario 2 --> Suivi ligne courbe
 * 
 * Scénario 3 --> Le robot opère tel un robot d'entrepôt, allant récupérer des objets dans une zone pour les retransmettre dans une autre zone
 * 
 */

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include <sensehat.h>


#include "my_lib/avanceCompose.hpp"
#include "my_lib/robotmove.hpp"

#include "my_lib/boussole.hpp"
#include "my_lib/capteur.hpp"
#include "my_lib/moteur.hpp"
#include "my_lib/foncTemps.hpp"

#include "my_lib/traject.hpp"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // system_clock, seconds, milliseconds
using namespace saeS1;

char prendre_chargement(int i)
{
    if(i==0)
    {
        return 'A';
    }
    else if (i==1)
    {
        return 'B';
    }
    else
    {
        return 'N';
    }
    
}


//SCENARIOS
void ligneDroite()
{
    //Permet au robot d'avancer en ligne droite durant 7s ou jusqu'a qu'il ateingne un valon
    cout << "Scénario ligne droite" <<endl;
    double cap = get_compas();
    temps_t temps0;
    get_temps(temps0);

    bool detectValon;
	do
	{
		detectValon = avance_valon(cap);
	}while(
        (!(detect_temps(7,temps0))
        && detectValon)
    );
}

//Scénar 1
void suiviLigneCourbe()
{
    //Permet au robot de suivre une ligne avec des virages

    cout << "Scénario ligne courbe" <<endl;
    bool detectValon= false;
    double cap;
   do
    {
        if (detec_Capt_Droit())
        {
            avance_Vitesse_Gauche(VITESSE_1);
        }
        else if (detec_Capt_Gauche())
        {
            avance_Vitesse_Droit(VITESSE_1);
        }
        else
        {
            cap = get_compas();
            detectValon = not(avance_valon(cap));
        }
    } while (detectValon);
    stop();
}

//Scénar 3
void scenEntrepot()
{
    cout << "Scénario Entrepôt" <<endl;
    double trajet[MAX_FONCTIONS][MAX_PARAMETRE];
    char chargement = 'N';//chargement vide

    cout<<"On est a la base\n";
    base_chargement(trajet);
    robot(trajet);


    for (int i = 0; i < 2; i++)
    {
        cout<<"On est au chargement\n";
        sleep_for(milliseconds(5000));

        chargement = prendre_chargement(i);

        if (chargement == 'A')
        {
            cout<<"On prend la marchandise A\n";
            chargement_A(trajet);
            robot(trajet);

            cout<<"On est au point A\n";
            cout<<"On vide le chargement A\n";
            chargement ='N';
            sleep_for(milliseconds(5000));
            
            A_chargement(trajet);
            robot(trajet);

        }
        else if (chargement == 'B')
        {
            cout<<"On prend la marchandise B\n";
            chargement_B(trajet);
            robot(trajet);

            cout<<"On est au point B\n";
            cout<<"On vide le chargement B\n";
            chargement ='N';
            sleep_for(milliseconds(5000));
            
            B_chargement(trajet);
            robot(trajet);
        }
        else
        {
            cout<<"Il n'y a pas de marchandise\n";
        }
        
    }

    chargement_base(trajet);
    robot(trajet);

    cout<<"On est a la base\n";
    cout<<"Fin du trajet\n";    
}

// Fin sous-programmes
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main() {
	if(senseInit()) {
		cout << "Sense Hat initialization Ok." << endl;

        //init
		init();

        //programme
        int debuter;
        bool exit = true;
        do
        {
            cout <<"Pour démarrer le robot merci de rentrer le scénario choisi : " << endl << "\t" 
                << "0 pour stop le programme"<< endl << "\t" 
                << "1 pour le suivi de ligne droite"<< endl << "\t" 
                << "2 pour le suivi de ligne avec courbes"<< endl << "\t" 
                << "3 pour le robot d'entrepôt"<< endl;
            cin>> debuter;        
            
            //selectionneur de scénario (mode)
            switch (debuter) {
                case 0:
                    exit = false;
                    break;
                case 1 :
                    ligneDroite();
                    break;
                case 2:
                    suiviLigneCourbe();
                    break;
                case 3:
                    scenEntrepot();
                    break;
                default:
                    break;
            }
        }while(exit);


		// Fin instructions
		// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		cout << "Press joystick button to quit." << endl;
		senseWaitForJoystickEnter();

		senseShutdown();
		cout << "Sense Hat shut down." << endl;
	}
	return EXIT_SUCCESS;
}