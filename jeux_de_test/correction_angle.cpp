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

//angle
const int DEGRE_ANGLE_LIB = 5;//angle liberter que l'on donne pour la detection d'angle

//Vitesse
const int VITESSE_0 = 0;
const int VITESSE_1 = 25;
const int VITESSE_2 = 50;
const int VITESSE_3 = 75;
const int VITESSE_4 = 100;

//Compass
const int INT_MESURES = 100;
const int DEGRE_ANGLE_LIB = 10;

// Fin constantes
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Déclaration des fonctions


double get_compas();
bool detect_angle(double angle);
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

void initCompas()
{
	int cpt;
	senseSetIMUConfig(true, true, true);
	for (cpt = 0; cpt < INT_MESURES; cpt++)
	{
		senseGetCompass();
	}
	cout << "initialisation faite" << endl;
}

void init()
{
    init_gpio();
    initCompas();
}



void avance_Vitesse_Droit(unsigned int vit)
{
    /*
    gere les impulsions de commande du moteur Gauche 
    en fonction d'une puissance en % (0 a 100)
        gpio raspberry
    */
    unsigned int puissance;
  /* if (vit <0)
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
   */
  puissance = vit;

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
   /*if (vit <0)
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
   */
  puissance = vit;
   
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

void avance_valon(unsigned int vit)
{
    /*
    Avance tout droit d'une distance dis en cm a une vitesse vit
    utilise
        - avance_vit
        - detec_2_Capt
        - stop
    */
   if (detec_2_Capt())
   {
    stop();
   }
   else
   {
    avance_vit(vit);
   }
   
}

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

double get_compas()
{
	return senseGetCompass();
}

bool calcul_Min_Max (double &min,double &max,double cap)
{
    double save_val;
	bool inverse = false;

    min = cap - DEGRE_ANGLE_LIB;
    max = cap + DEGRE_ANGLE_LIB;
	save_val = max;

    if(min < 0)
	{
		max = 360 + min;
		min = save_val;
		inverse = true;
	}
	else if(max > 360)
	{
		max = max - 360;
		min = save_val;
		inverse = true;
	}
    return inverse;
}

bool detect_angle(double cap)
{
    double angle;
    double min,max;
	double save_val;

    angle = get_compas();


	if (calcul_Min_Max(min,max,cap))
	{
		if (!(angle >= min && angle <= max))
    	{
			return true;
    	}
    }
	else
    {
         if (angle >= min && angle <= max)
         {
             return true;
         }
    }
    return false;
    
}

void correction_angle(double angle_cap)
{
    /*
    corrige l'angle en fonction a quelle point il est deporte de sa direction
    utilise
        - avance_Vitesse_Droit
        - avance_Vitesse_Gauche
        - get_angle
        - detect_angle
    */
    double min,max;
	double angle;

    angle = get_compas();

    if (calcul_Min_Max(min,max,cap))
    {
        //cas inversé
        if(angle < min)
        {
            avance_Vitesse_Gauche(VITESSE_4);
            avance_Vitesse_Droit(VITESSE_1)
        }
        else if (angle > max)
        {
            avance_Vitesse_Gauche(VITESSE_4);
            avance_Vitesse_Droit(VITESSE_1);
        }
        else avance_valon(VITESSE_4);
    }
    else
    {
        //cas non inversé
        //On prends en compte que la boussole fonctionne en sens trogonométrique(anti-horraire)
        if(angle < min)
        {
            avance_Vitesse_Gauche(VITESSE_1);
            avance_Vitesse_Droit(VITESSE_4)
        }
        else if (angle > max)
        {
            avance_Vitesse_Gauche(VITESSE_4);
            avance_Vitesse_Droit(VITESSE_1);
        }
        else avance_valon(VITESSE_4);
    }


	
    

}

void avance_Cap(double cap)
{
    
    do
    {
        
		if(detect_angle(cap))
		{
			avance_valon(VITESSE_4);
		}
		else
		{
			correction_angle(cap);
		}

    } while (true);
}


//test
void test_cap()
{
    double cap;
    cap = 1; //get_compas();
    avance_Cap(cap);
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
        do
        {
            cout <<"Pour démarrer le robot merci de rentrer le scénario choisi : " << endl << "\t" 
                << "0 pour stop le programme"<< endl << "\t" 
                << "1 pour le suivi de ligne droite"<< endl << "\t" 
                << "2 pour le suivi de ligne avec courbes"<< endl << "\t" 
                << "3 pour le robot d'entrepôt"<< endl;
                << "4 pour le test d'une fonction"<< endl;
            cin>> debuter;        
            
            //selectionneur de scénario (mode)
            
            switch (debuter) {
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