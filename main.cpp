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

void gestionVitesseD()
{

}

void gestionVitesseG()
{

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
    /*Affiche la puissance des moteurs gauche et droite sur l'afficheur LED (en vertical)
     ainsi que la répartition de puissance entre les deux moteurs (horizontal)

*/
}


//F5 Gestion du Joystick


//F6 Gestion du Clavier


//F7 Gestion Démarrage / Arrêt

int demarrer(int debuter)
{
    //Démarre le robot (si cette fonction n'est pas appelée, le robot ne fait rien)
    int debut;

    do
    {
        cout <<"Pour démarrer le robot merci de rentrer le scénario choisi : " << endl << "\t" 
            << "-1 pour le suivi de ligne droite"<< endl << "\t" 
            << "-2 pour le suivi de ligne avec courbes"<< endl << "\t" 
            << "-3 pour le robot d'entrepôt"<< endl;
        cin>> debut;        
    }while(debut < 0 || debut >3);
    return debut;
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
    cout << "Scénario ligne droite" <<endl;
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

    int debuter;
    
    //selectionneur de scénario (mode)
    debuter = demarrer(debuter);
    
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
    }

    return 0;
}
