/* File: robot_.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *Ce programme à pour but de permettre les test des fonctions ddes capteur de ligne
 */

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include <sensehat.h>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // system_clock, seconds, milliseconds

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Début constantes
//capteur 
const unsigned int PIN_CAPT_GAUCHE = 16;
const unsigned int PIN_CAPT_DROIT= 17;
// Fin constantes
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Déclaration des fonctions

void stop();

// Fin Fonctions 
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Début sous-programmes
void init_gpio()
{
    gpioSetConfig(PIN_CAPT_GAUCHE, in);
    gpioSetConfig(PIN_CAPT_DROIT, in);

    pwmInit(CHAN_MOT_DROIT);
    pwmPeriod(CHAN_MOT_DROIT, PERIODE_MS);
    pwmDutyCycle(CHAN_MOT_DROIT,0);
    pwmEnable(CHAN_MOT_DROIT);

    pwmInit(CHAN_MOT_GAUCHE);
    pwmPeriod(CHAN_MOT_GAUCHE, PERIODE_MS);
    pwmDutyCycle(CHAN_MOT_GAUCHE,0);
    pwmEnable(CHAN_MOT_GAUCHE);
}

void init()
{
    init_gpio();
}



//F2 Détection des capteurs
bool detec_Capt_Droit()
{
    /*
    Renvois Vrais si le capteur Droit detecte une bande noir
    utilise
        gpio raspberry
    */
    bool detect;
    detect= false;
    if (gpioGetInput(PIN_CAPT_DROIT) ==0)
    {
       detect = true;
    }
    return detect;
}

bool detec_Capt_Gauche()
{
    /*
    Renvois Vrais si le capteur Gauche detecte une bande noir
    utilise
        gpio raspberry
    */
    bool detect;
    detect= false;
    if (gpioGetInput(PIN_CAPT_GAUCHE) == 0)
    {
       detect = true;
    }
    return detect;
}

bool detec_2_Capt()
{
    /*
    Renvois Vrais si les 2 capteurs detecte une bande noir
    utilise
        - detec_Capt_Gauche
        - detec_Capt_Droit
    */
    bool detect;
    detect = detec_Capt_Droit() && detec_Capt_Gauche();
    return detect;
}

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
		init();

        //programme
        int debuter;
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
                case 1 :
                    test();
                    break;
                default:
                    break;
            }
        }while(true);
		// Fin instructions
		// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		cout << "Press joystick button to quit." << endl;
		senseWaitForJoystickEnter();

		senseShutdown();
		cout << "Sense Hat shut down." << endl;
	}

	return EXIT_SUCCESS;
}