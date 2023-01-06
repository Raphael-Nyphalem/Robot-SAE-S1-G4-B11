#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <sensehat.h>
using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // system_clock, seconds, milliseconds





const int MAX_AFFICHE_X = 8;
const int MAX_AFFICHE_Y = 8;


//FONCTIONS

//F1 Gestion des moteurs
void moteurDroit()
{
    //gere les impulsions de commande du moteur Gauche

}

void moteurGauche()
{
    //gere les impulsions de commande du moteur Gauche
}

//F2 Détection des capteurs

void detectionCaptDroit()
{
    //gère la détection d'une sortie de ligne
}

void detectionCaptGauche()
{
    //gère la détection d'une sortie de ligne
}

//F3 Contrôle de direction


//F4 Gestion d'affichage
void affichagePuissance()
{
    //Affiche la puissance des moteurs gauche et droite sur l'afficheur LED (en vertical)ainsi que la répartition de puissance entre les deux moteurs (horizontal)
}


//F5 Gestion du Joystick


//F6 Gestion du Clavier


//F7 Gestion Démarrage / Arrêt

void demarrer()
{
    //Démarre le robot (si cette fonction n'est pas appelée, le robot ne fait rien)
}

void arretProgressif()
{
    //Arrête progressivement les moteurs du robot en abaissant leur puissance jusqu'à 0%
}

void arretUrgence()
{
    //Arrête les moteurs du robot instantanément
}


//SCENARIOS
//Scénar 0
void ligneDroite()
{
    //Permet au robot d'avancer en ligne droite
}

//Scénar 1
void suiviLigne()
{
    //Permet au robot de suivre une ligne avec des virages
}

//Scénar 2
void demiTour()
{
    //Permet au robot de faire demi-tour une fois arrivé en bout de ligne
}

//Scénar 3
void choixIntersection()
{
    //Permet à l'utilisateur de définir une direction à emprunter une fois arrivé à une intersection
}






int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
