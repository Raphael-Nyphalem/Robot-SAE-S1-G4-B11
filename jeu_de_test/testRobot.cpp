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

#include <sensehat.h>

#include "../my_lib/robotmove.hpp"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // system_clock, seconds, milliseconds

using namespace saeS1;

//TEST execute
void test_avance_Valon()
{
    double avanceValon[MAX_PARAMETRE]= {1,1,-1,0,0};
    cout<<"debut test avance Valon\n";
    execute_etape(avanceValon);
    cout<<" fin test avance Valon\n";
}

void test_avance_temps()
{
    double avanceTempsCap[MAX_PARAMETRE]= {2,1,10,-1,0};
    cout<<"debut test avance Temps cap (cap du robot durant 10s)\n";
    execute_etape(avanceTempsCap);
    cout<<" fin test avance Temps cap\n";
}

void test_tourne_droite()
{
    double tourneCap[MAX_PARAMETRE]={3,1,90,0,0};
    cout<<"debut test tourne cap (de 90° vest la droite)\n";
    execute_etape(tourneCap);
    cout<<" fin test avance tourne cap\n";
}
void test_execute()
{
    double stop[MAX_PARAMETRE]={0,1,0,0,0};
    double avanceValon[MAX_PARAMETRE]= {1,1,-1,0,0};
    double avanceTempsCap[MAX_PARAMETRE]= {2,1,10,-1,0};
    double tourneCap[MAX_PARAMETRE]={3,1,90,0,0};

    cout<<"debut test avance Valon\n";
    execute_etape(avanceValon);
    cout<<" fin test avance Valon\n";

    cout<<"debut test avance Temps cap (cap du robot durant 10s)\n";
    execute_etape(avanceTempsCap);
    cout<<" fin test avance Temps cap\n";

    cout<<"debut test tourne cap (de 90° vest la droite)\n";
    execute_etape(tourneCap);
    cout<<" fin test avance tourne cap\n";

    cout<<"debut test stop\n";
    avance_vit(100);
    cout<<"on avance 2s avant de stop\n";
    sleep_for(milliseconds(2000));
    execute_etape(stop);
    cout<<" fin test stop\n";
    
}


//TEST
void test_robot()
{
    //Permet au robot d'avancer en ligne droite (simple) durant 1s
    cout << "Scénario avance_valon " <<endl;
    //trajet base A
    double trajet1[MAX_FONCTIONS][MAX_PARAMETRE]=
        {
        {1,1,100,0,0},
        {2,1,0.5,-1,0},
        {3,1,90,0,0},
        {1,1,100,0,0},
        {3,1,90,0,0},

        {1,1,100,0,0},
        {2,1,1,-1,0},
        {1,1,100,0,0},
        {3,1,-90,0,0},
        {1,1,100,0,0},

        {0,1,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}};

    robot(trajet1);

    

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
            cout <<"Pour démarrer le robot merci de rentrer le scénario choisi : " << endl 
                << "\t0 pour stop le programme"<< endl 
                << "\t1 pour les test de la fonction execute "<<endl
                << "\t2 pour le test de la fonction robot"<<endl
                << "\t3 pour le test de la fonction robot"<<endl
                << "\t4 pour le test de la fonction robot"<<endl
                << "\t5 pour le test de la fonction robot"<<endl;
            cin>> debuter;        
            
            //selectionneur de scénario (mode)
            
            switch (debuter) {
                case 0:
                    exit = false;
                    break;
                case 1 :
                    test_execute();
                    break;
                case 2:
                    test_robot();
                    break;
                case 3:
                    test_avance_Valon();
                    break;
                case 4:
                    test_avance_temps();
                    break;
                case 5:
                    test_tourne_droite();
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