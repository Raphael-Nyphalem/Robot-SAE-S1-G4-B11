/* File: robot_.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *Ce programme à pour but de permettre les test des fonctions ddes capteur de ligne
 */

#include "../my_lib/capteur.hpp"

using namespace saeS1;
void test()
{
    do
    {
        if(detect_2_Capt())
        {
            cout << "Les deux capteurs détectent" << endl;
        }
        else if(detect_Capt_Droit())
        {
            cout << "Le capteur droit détecte" << endl;
        }
        else if(detect_Capt_Gauche())
        {
            cout << "Le capteur gauche détecte" << endl;
        }
        else
        {
            cout << "Aucun capteur ne détecte" << endl;
        }
    } while (true);
    
}



int main() {
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Début variables

	// Fin variables
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	if(senseInit()) {
		cout << "Sense Hat initialization Ok." << endl;
		// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// Début instructions

		init_gpio_capteur();

        //programme
        int debuter;
        bool exitboucle = true;
        do
        {
            cout <<"Pour démarrer le robot merci de rentrer le scénario choisi : " << endl << "\t" 
                << "0 pour stop le programme"<< endl << "\t" 
                << "1 pour le test des capteurs"<< endl;
            cin>> debuter;        
            
            //selectionneur de scénario (mode)
            
            switch (debuter) {
                case 0:
                    exitboucle=false;
                    break;
                case 1 :
                    test();
                    break;
                default:
                    break;
            }
        }while(exitboucle);
		// Fin instructions
		// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		cout << "Press joystick button to quit." << endl;
		senseWaitForJoystickEnter();

		senseShutdown();
		cout << "Sense Hat shut down." << endl;
	}

	return EXIT_SUCCESS;
}