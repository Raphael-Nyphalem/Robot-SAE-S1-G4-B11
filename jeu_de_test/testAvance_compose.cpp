/* File:
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

#include <sensehat.h>

#include "../my_lib/avanceCompose.hpp"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // system_clock, seconds, milliseconds

using namespace saeS1;



//TEST
void test_correcton_cap()
{
    //Permet au robot d'avancer en ligne droite (simple) durant 1s
    cout << " test_correcton_cap " <<endl;
    double cap;
    temps_t tps0;

    get_temps(tps0);
    //cas inverse (cap proche de 0)
    cap = 1;
    cout << "Debut cas inverse (cap proche de 0) " <<endl;
    do
    {
        correction_angle(cap);
    } while (!(detect_temps(10,tps0)));
    stop();
    cout << "Fin cas inverse (cap proche de 0) " <<endl;
    
    sleep_for(seconds(5));

    //cas non-inverse
    //cas entre 0 et 180,
    cap = 90;
    get_temps(tps0);
    cout << "Debut cas non-inverse cap entre 0 et 180 " <<endl;
    do
    {
        correction_angle(cap);
    } while (!(detect_temps(10,tps0)));
    stop();
    cout << "Fin cas non-inverse cap entre 0 et 180 " <<endl;

    sleep_for(seconds(5));

    //cas entre 180 et 360,
    cap = 270;
    get_temps(tps0);
    cout << "Debut cas non-inverse cap entre 180 et 360 " <<endl;
    do
    {
        correction_angle(cap);
    } while (!(detect_temps(10,tps0)));
    stop();
    cout << "Fin cas non-inverse cap entre 180 et 360 " <<endl;

    

}


void test_Avance_Valon()
{
    //Permet au robot d'avancer en ligne droite (simple) durant 1s
    cout << "Scénario avance_valon " <<endl;

    double cap;
    cap = get_compas()
    while (avance_valon(cap))
    {
        /* on avance vers le cap jusqu'a un valon */
    }

}


void test_Avance_cap_temps()
{
    //Permet au robot d'avancer en ligne droite vers OUEST durant 5s
    cout << "Scénario test_Avance_cap_temps " <<endl;
    temps_t  temps0;
    get_temps(temps0);
    while(avance_temps_cap(5,90,temps0)){};

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
                << "1 pour les test_correcton_cap"<< endl << "\t"
                << "2 pour le test_Avance_cap_temps (5s) direction 90"<<endl<< "\t"
                << "3 pour le test_Avance_Valon" <<endl;
            cin>> debuter;        
            
            //selectionneur de scénario (mode)
            
            switch (debuter) {
                case 0:
                    exit = false;
                    break;
                case 1 :
                    test_correcton_cap();
                    break;
                case 2:
                    test_Avance_cap_temps();
                    break;
                case 3 :
                    test_Avance_Valon();
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