/* File: robot_.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *Ce programme à pour but de permettre les test des fonctions du moteur
 */

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include <sensehat.h>
#include "../my_lib/moteur.hpp"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // system_clock, seconds, milliseconds
using namespace saeS1;

//TEST

void test_avance_Vitesse_Droit()
{
    cout<< "test avance_Vitesse_Gauche()"<<endl;
    avance_Vitesse_Droit(VITESSE_2);
    sleep_for(seconds(5));
    cout<< "test stop_Mot_Droit() "<<endl;
    stop_Mot_Droit();
    
}

void test_avance_Vitesse_Gauche()
{
    cout<< "test avance_Vitesse_Gauche"<<endl;
    avance_Vitesse_Gauche(VITESSE_2);
    sleep_for(seconds(5));
    cout<< "test stop_Mot_Gauche "<<endl;
    stop_Mot_Gauche();
    
}
void test_avance_vit()
{
    cout<< "test avance_vit()"<<endl;
    avance_vit(VITESSE_2);
    sleep_for(seconds(5));
    cout<< "test stop()"<<endl;
    stop();
    
}

// Fin sous-programmes
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



int main()
{
    if(senseInit()) {
		cout << "Sense Hat initialization Ok." << endl;
		// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// Début instructions
		init_gpio_moteur();

        //programme
        int debuter;
        bool exitboucle = true;
        do
        {
            cout <<"Pour démarrer le robot merci de rentrer le scénario choisi : " << endl << "\t" 
            << "1 pour test_avance_Vitesse_Droit();"<< endl << "\t" 
            << "2 test_avance_Vitesse_Gauche();"<< endl << "\t" 
            << "3 test_avance_vit();"<< endl << "\t"
            << "autre stop le programme"<< endl;

            cin>> debuter;     
            switch (debuter) {
                case 0:
                    exitboucle = false;
                    break;
                case 1 :
                    test_avance_Vitesse_Droit();
                    break;
                case 2 :
                    test_avance_Vitesse_Gauche();
                    break;
                case 3 :
                    test_avance_vit();
                    break;
                default:
                    break;
                }
        } while (exitboucle);

        // Fin instructions
		// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		cout << "Press joystick button to quit." << endl;
		senseWaitForJoystickEnter();

		senseShutdown();
		cout << "Sense Hat shut down." << endl;
	}

}