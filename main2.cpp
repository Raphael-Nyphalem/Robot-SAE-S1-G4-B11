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


#include "my_lib/boussole.hpp"
#include "my_lib/capteur.hpp"
#include "my_lib/moteur.hpp"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // system_clock, seconds, milliseconds
using namespace saeS1;

//SCENARIOS
void ligneDroite()
{
    //Permet au robot d'avancer en ligne droite
    cout << "Scénario ligne droite" <<endl;
    unsigned int vit = VITESSE_2;
    
	do
	{
		avance_valon(vit);
		sleep_for(milliseconds(100));
	}while(true);
}

//Scénar 1
void suiviLigneCourbe()
{
    //Permet au robot de suivre une ligne avec des virages

    cout << "Scénario ligne courbe" <<endl;
   do
    {
         if(detec_2_Capt())
        {
            stop();
        }
        else if (detec_Capt_Droit())
        {
            avance_Vitesse_Gauche(VITESSE_1);
        }
        else if (detec_Capt_Gauche())
        {
            avance_Vitesse_Droit(VITESSE_1);
        }
        else
        {
            avance_valon(VITESSE_4);
        }
    } while (true);

   
}

//Scénar 3
void scenEntrepot()
{
    cout << "Scénario Entrepôt" <<endl;
}

// Fin sous-programmes
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main() {
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Début variables

	// Fin variables
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	if(senseInit()) {
		cout << "Sense Hat initialization Ok." << endl;
		// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// Début instructions
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
                case 1 :
                    ligneDroite();
                    break;
                case 2:
                    suiviLigneCourbe();
                    break;
                case 3:
                    scenEntrepot();
                    break;
				case 4:
                    test();
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