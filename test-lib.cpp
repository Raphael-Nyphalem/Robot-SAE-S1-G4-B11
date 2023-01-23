/* File: robot_.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *
 * 
 */

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <string>

#include <sensehat.h>

#include "my_lib/avanceCompose.hpp"
#include "my_lib/moteur.hpp"
#include "my_lib/boussole.hpp"
#include "my_lib/capteur.hpp"
#include "my_lib/foncTemps.hpp"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // system_clock, seconds, milliseconds

using namespace saeS1;



//TEST
void test_Avance_Valon()
{
    //Permet au robot d'avancer en ligne droite (simple) durant 1s
    cout << "Scénario avance_valon " <<endl;
    unsigned int vit = VITESSE_4;

	
    bool exit_test;
    do
    {
        exit_test = avance_valon(vit);
    } while (exit_test);
    
    stop();

}


void test_Avance_cap_temps()
{
    //Permet au robot d'avancer en ligne droite vers OUEST durant 5s
    cout << "Scénario test_Avance_cap_temps " <<endl;
    temps_t temps0;
    get_temps(temps0);
    bool exit_test;
    do
    {
        exit_test =avance_temps_cap(5,90,temps0);
    } while (exit_test);
    

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
                << "1 pour le test_Avance_Valon"<<endl
                << "2 pour le test_Avance_cap_temps (5s) direction 90"<<endl;
            cin>> debuter;        
            
            //selectionneur de scénario (mode)
            
            switch (debuter) {
                case 0:
                    exit = false;
                    break;
                case 1 :
                    test_Avance_Valon();
                    break;
                case 2:
                    test_Avance_cap_temps();
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