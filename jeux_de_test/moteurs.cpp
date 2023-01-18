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

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // system_clock, seconds, milliseconds

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Début constantes
//capteur 
const unsigned int PIN_CAPT_GAUCHE = 16;
const unsigned int PIN_CAPT_DROIT= 17;

//moteur
const unsigned int CHAN_MOT_GAUCHE = 0;
const unsigned int CHAN_MOT_DROIT= 1;

const unsigned int PERIODE_MS = 10000;

//ecran
const int MAX_AFFICHE_X = 8;
const int MAX_AFFICHE_Y = 8;

//Vitesse
const int VITESSE_0 = 0;
const int VITESSE_1 = 25;
const int VITESSE_2 = 50;
const int VITESSE_3 = 75;
const int VITESSE_4 = 100;

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


void avance_Vitesse_Droit(unsigned int vit)
{
    /*
    gere les impulsions de commande du moteur Gauche 
    en fonction d'une puissance en % (0 a 100)
        gpio raspberry
    */
    unsigned int puissance;
    if (vit <0)
    {
        puissance = 0;
    }
    else if (vit>100)
    {
        puissance =100;
    }
    else
    {
        puissance = vit;
    }

   pwmDutyCycle(CHAN_MOT_GAUCHE,puissance);

}

void avance_Vitesse_Gauche(unsigned int vit)
{
    /*
    gere les impulsions de commande du moteur Droit 
    en fonction d'une puissance en % (0 a 100)
    utilise
        gpio raspberry
    */
   unsigned int puissance;
   if (vit <0)
   {
    puissance = 0;
   }
   else if (vit>100)
   {
    puissance =100;
   }
   else
   {
    puissance = vit;
   }
   
   pwmDutyCycle(CHAN_MOT_DROIT,puissance);

}

void avance_vit(unsigned int vit)
{
    /*
    utilise
        - avance_Vitesse_Droit
        - avance_Vitesse_Gauche
        - detect_angle
        - correction_angle
    */
    avance_Vitesse_Droit(vit);
    avance_Vitesse_Gauche(vit);
   
}

void stop_Mot_Gauche()
{
    /*
    arret du moteur Gauche
    utilise 
        - gestion_mot_Gauche
    */
   pwmDutyCycle(CHAN_MOT_GAUCHE,0);
}

void stop_Mot_Droit()
{
    /*
    arret du moteur Gauche
    utilise 
        - gestion_mot_Gauche
    */
   pwmDutyCycle(CHAN_MOT_DROIT,0);
}


/

void stop()
{
    /*
    Permet d'arreter le robot
    utilise 
        - stop_Mot_Droit 
        - stop_Mot_Gauche
    */
   stop_Mot_Droit();
   stop_Mot_Gauche();
}
int debuter;
        bool exit = true;


//TEST
void test_avance_Vitesse_Droit()
{
    out<< "test avance_Vitesse_Gauche()"<<endl;
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
                << "1 pour test moteur droit"<<endl
                << "2 pour test moteur gauche"<<endl
                << "3 pour test 2 moteur"<<endl;
            cin>> debuter;        
            
            //selectionneur de scénario (mode)
            
            switch (debuter) {
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