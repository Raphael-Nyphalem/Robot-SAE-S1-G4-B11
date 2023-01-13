/* File: main.cpp
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

//capteur 
const unsigned int PIN_CAPT_GAUCHE = 16;
const unsigned int PIN_CAPT_DROIT= 17;

//moteur
const unsigned int CHAN_MOT_GAUCHE = 0;
const unsigned int CHAN_MOT_DROIT= 1;

const unsigned int PERIODE_MS = 50;

//ecrant
const int MAX_AFFICHE_X = 8;
const int MAX_AFFICHE_Y = 8;

//angle
const int DEGRE_ANGLE_LIB = 5;//angle liberter que l'on donne pour la detection d'angle

//FONCTIONS
void correction_angle(int angle,int vit);
int get_angle();
bool detect_angle(int angle);

//Vitesse
const int VITESSE_0 = 0;
const int VITESSE_1 = 25;
const int VITESSE_2 = 50;
const int VITESSE_3 = 75;
const int VITESSE_4 = 100;


//F1 Gestion des moteurs
void avance_Vitesse_Droit(int vit)
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
    puissance =100
   }
   else
   {
    puissance = vit;
   }

   pwmDutyCycle(CHAN_MOT_GAUCHE,puissance);

}

void avance_Vitesse_Gauche(int vit)
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
    puissance =100
   }
   else
   {
    puissance = vit;
   }
   
   pwmDutyCycle(CHAN_MOT_DROIT,puissance);

}

void avance_vit(int vit)
{
    /*
    utilise
        - avance_Vitesse_Droit
        - avance_Vitesse_Gauche
        - detect_angle
        - correction_angle
    */
   double angle = get_angle();

   if(detect_angle(angle))
   {
    avance_Vitesse_Droit(vit);
    avance_Vitesse_Gauche(vit);
   }
   else
   {
    correction_angle(angle,vit);
   }
   
}

void stop_Mot_Gauche()
{
    /*
    arret du moteur Gauche
    utilise 
        - gestion_mot_Gauche
    */
   pwmDutyCycle(CHAN_MOT_GAUCHE,0)
}

void stop_Mot_Droit()
{
    /*
    arret du moteur Gauche
    utilise 
        - gestion_mot_Gauche
    */
   pwmDutyCycle(CHAN_MOT_DROIT,0)
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
    if (gpioGetInput(PIN_CAPT_DROIT) >0.5)
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
    if (gpioGetInput(PIN_CAPT_GAUCHE) > 0.5)
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
    detect = (detec_Capt_Droit && detec_Capt_Gauche)
    return detect;
}

//F3 Contrôle de mouvement
void avance_dis(int dis,int vit)
{
    /*
    Avance tout droit d'une distance dis en cm a une vitesse vit
    utilise
        - avance_vit
        - detect_temp
        - stop
    */

}

void avance_valon(int vit)
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
    avance_vit(vit);
   }
   else
   {
    stop();
   }
   
}

void tourne(int angle)
{
    /*
    Tourne d'une angle angle en degré 

    utilise 
        - stop
        - avance_Vitesse_Droit
        - avance_Vitesse_Gauche
        - detect_angle
    */
}

void demit_tour()
{
    /*
    Permet de faire un demit tour donc revenir a sont point inital dans l'autre sens
    utilise
        - avance_dis
        - tourne
    */
}

void demit_tour_valon()
{
    /*
    Permet de faire un demit tour donc revenir a sont point inital dans l'autre sens
    utilise
        - avance_dis
        - tourne
        - avance_valon
    */
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


//F4 Gestion d'affichage 
//ATTENTION les inputs ne sont pas encore fais
void affich_Puissance_mot()
{
    /*
    Affiche la puissance des moteurs gauche et droite sur l'afficheur LED (en vertical)
    utilise
        <sensehat.h>
    */
}

void affich_repart_puissance()
{
    /*
    Affiche la répartition de puissance entre les deux moteurs (horizontalement)
    utilise
        <sensehat.h>
    */
}

void affich_perdu()
{
    /*
    Affiche le message si le robot est perdu
    utilise
        <sensehat.h>
    */
}

void affich_chargement()
{
    /*
    Affiche l'object qui est charger
    utilise
        <sensehat.h>
    */
}

void affich_direction()
{
    /*
    Affiche le prochain itineraire du robot
    utilise
        <sensehat.h>
    */
}


//F5 Gestion du Joystick
bool detect_HAUT()
{
    /*
    detect si on met le joystick vers le haut
    utilise
        <sensehat.h>
    */
    bool detect;
    //code
    return detect;
}

bool detect_BAS()
{
    /*
    detect si on met le joystick vers le bas
    utilise
        <sensehat.h>
    */
    bool detect;
    //code
    return detect;
}

bool detect_Droite()
{
    /*
    detect si on met le joystick vers la droite
    utilise
        <sensehat.h>
    */
    bool detect;
    //code
    return detect;
}

bool detect_Gauche()
{
    /*
    detect si on met le joystick vers la gauche
    utilise
        <sensehat.h>
    */ 
    bool detect;
    //code
    return detect; 
}

bool detect_Bouton()
{
    /*
    detect si on appuit sur le joystick
    utilise
        <sensehat.h>
    */ 
    bool detect;
    //code
    return detect; 
}


//F6 Gestion du Clavier
char clavier()
{   
    /*
    recupère les inputs clavier
    INPUT ET OUTPUT PAS ENCORE DEFINITIF
    utilise
    */
    char clv;
    //code
    return clv;
}

bool detect_clavier(size_t touche)
{
    /*
    detecte un input clavier 
    utilise
        clavier
    */
    bool detect;
    //code
    return detect;
}


//F7 timeur
bool detect_temp(int time_x, int time_init)
{
    /*
    detecte lorsque le temps passe au dessus du temps time_init + time_x
    Time_x la difference de temps que l'on souhaite utilise
    utilise
        <clavierchrono>
    */
    bool detect;
    //code
    return detect;
}


//F8 gestion Boussole
double get_angle()
{
    /*
    Permet d'optenir l'angle actuel de la boussole
    utilise
        <sensehat.h>
    */
    double angle;
    angle senseGetCompass();
    return angle;
}

bool detect_angle(double angle)
{
    /*
    detecte si on est dans la plage de l'angle donnez
    par plage je veux dire l'angle a + ou - un degré d'angle donner par la constante DEGRE_ANGLE_LIB
    utilise
        get_angle
    */
        bool detect = false;
        double angle_actuel = get_angle();
        double min = angle - DEGRE_ANGLE_LIB;
        double max = angle + DEGRE_ANGLE_LIB;
        if (angle_actuel >= min && angle_actuel <= max)
        {
            detect = true;
        } 
    return detect;
}


//F9 Autre
void perdu()
{
    /*
    detecte si on est dans la plage de l'angle donnez
    par plage je veux dire l'angle a + ou - un degré d'angle donner par la constante DEGRE_ANGLE_LIB
    utilise
        - stop
        - affich_perdu
    */

}

int temps_dis(int dis, int vit)
{
    /*
    permet de calculer le temps sur une distance donnez a un "vitesse" donnez
    permet ainci de calculer la vitesse en cm/s
    utilise
        - avance_valon
        - <chrono>
    */
    int time;
    //code
    return time;
}

void securiter(int timemax,int time_init)
{
    /*
    Arrete le robot si il met trop de temps a passer une étape
    utilise
        - perdu
        - <chrono>
    */
}

void correction_angle(double angle_cap,int vit)
{
    /*
    corrige l'angle en fonction a quelle point il est deporte de sa direction
    utilise
        - avance_Vitesse_Droit
        - avance_Vitesse_Gauche
        - get_angle
        - detect_angle
    */
    double dif;
    dif=angle_cap -get_angle();
    if (dif < 0)
    {
        avance_Vitesse_Gauche()//++
        avance_Vitesse_Droit()//--
    }
    else
    {
        avance_Vitesse_Droit()//++
        avance_Vitesse_Gauche()//--
    }
    

}



//F10 Trajet

void base_chargement()
{
    /*
    Décrit le chemin de la base du robot pour recharger sa batterie a la zone de chargement de la marchandise
    utilise 
        - avance_valon
        - tourne_valon
        - affich_direction
        - stop
    */
}

void chargement_A()
{
    /*
    Décrit le chemin de la zone de chargement de la marchandise au point A
    utilise 
        - avance_valon
        - tourne_valon
        - affich_direction
        - stop
    */
}

void chargement_B()
{
    /*
    Décrit le chemin de la zone de chargement de la marchandise au point B
    utilise 
        - avance_valon
        - tourne_valon
        - affich_direction
        - stop
    */
}

void A_chargement()
{
    /*
    Décrit le chemin du point A j'usqu'a la zone de chargement de la marchandise 
    utilise 
        - avance_valon
        - tourne_valon
        - affich_direction
        - stop
    */
}

void B_chargement()
{
    /*
    Décrit le chemin du point B j'usqu'a la zone de chargement de la marchandise 
    utilise 
        - avance_valon
        - tourne_valon
        - affich_direction
        - stop
    */
}

void A_base()
{
    /*
    Décrit le chemin du point A j'usqu'a la base 
    utilise 
        - avance_valon
        - tourne_valon
        - affich_direction
        - stop
    */
}

void B_base()
{
    /*
    Décrit le chemin du point B j'usqu'a la base 
    utilise 
        - avance_valon
        - tourne_valon
        - affich_direction
        - stop
    */
}

//SCENARIOS
//Scénar 0
void ligneDroite()
{
    //Permet au robot d'avancer en ligne droite
    cout << "Scénario ligne droite" <<endl;
    avance_valon(50);
}

//Scénar 1
void suiviLigneCourbe()
{
    //Permet au robot de suivre une ligne avec des virages

    cout << "Scénario ligne courbe" <<endl;
}

//Scénar 3
void scenEntrepot()
{
    cout << "Scénario Entrepôt" <<endl;
}



//Scénar 3.1

//Scénar 3.2

//Scénar 3.3

//Scénar 3.4





int main(int argc, char const *argv[])
{
    if(initCompas())
    {
            senseSetIMUConfig(true, true, false);

        //init
            gpioSetConfig(PIN_CAPT_GAUCHE , in);
            gpioSetConfig(PIN_CAPT_DROIT, in);

            pwmInit(CHAN_MOT_DROIT);
            pwmPeriod(CHAN_MOT_DROIT, PERIODE_MS);
            pwmDutyCycle(CHAN_MOT_DROIT,0);
            pwmEnable(CHAN_MOT_DROIT);

            pwmInit(CHAN_MOT_GAUCHE);
            pwmPeriod(CHAN_MOT_GAUCHE, PERIODE_MS);
            pwmDutyCycle(CHAN_MOT_GAUCHE,0);
            pwmEnable(CHAN_MOT_GAUCHE);

        //programme
        int debuter;
        bool end = false;

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
                    ligneDroite();
                    break;
                case 2:
                    suiviLigneCourbe();
                    break;
                case 3:
                    scenEntrepot();
                    break;
                case 0:
                    end = true;
                default:
                    break;
            }
        }while(!end);
    }

    return 0;
}
