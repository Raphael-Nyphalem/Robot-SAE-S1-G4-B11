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
void gestion_mot_Droit(int puissance)
{
    /*
    gere les impulsions de commande du moteur Droit 
    en fonction d'une puissance en %
    */
}

void gestion_mot_Gauche(int puissance)
{
    /*
    gere les impulsions de commande du moteur Gauche 
    en fonction d'une puissance en %
    */
}

void avance_Vitesse_Droit(int vit)
{
    /*
    utilise 
        - gestion_mot_Droit
    */

}

void avance_Vitesse_Gauche(int vit)
{
    /*
    utilise 
        - gestion_mot_Gauche
    */
}

void avance_vit(int vit)
{
    /*
    utilise
        - avance_Vitesse_Droit
        - avance_Vitesse_Gauche
    */   
}

void stop_Mot_Gauche()
{
    //
}

void stop_Mot_Droit()
{
    //
}


//F2 Détection des capteurs
bool detec_Capt_Droit()
{
    bool detect;
    //Renvois Vrais si le capteur Droit detecte une bande noir
    return detect;//bool
}

bool detec_Capt_Gauche()
{
    //Renvois Vrais si le capteur Gauche detecte une bande noir
    bool detect;
    return detect;
}

bool detec_2_Capt()
{
    //Renvois Vrais si les deuc capteurs detecte une bande noir
    bool detect;
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
void avance_valon(int dis,int vit)
{
    /*
    Avance tout droit d'une distance dis en cm a une vitesse vit
    utilise
        - avance_vit
        - detec_2_Capt
        - stop
    */
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
}


//F4 Gestion d'affichage 
// ATENTION les input ne sont pas encore fais
void affich_Puissance_mot()
{
    /*
    Affiche la puissance des moteurs gauche et droite sur l'afficheur LED (en vertical)
     ainsi que la répartition de puissance entre les deux moteurs (horizontal)
    */
}

void affich_repart_puissance()
{
    //
}

void affich_perdu()
{
    //
}

void affich_chargement()
{
    //
}

void affich_direction()
{
    //
}


//F5 Gestion du Joystick
bool detect_HAUT()
{
    //
    bool detect;
    return detect;
}

bool detect_BAS()
{
    //
    bool detect;
    return detect;
}

bool detect_Droite()
{
    //  
    bool detect;
    return detect;
}

bool detect_Gauche()
{
    //  
    bool detect;
    return detect; 
}

bool detect_Bouton()
{
    //   
    bool detect;
    return detect; 
}

//F6 Gestion du Clavier
char clavier()
{
    char clv;
    return clv;
}

bool detect_clavier(size_t touche)
{
    bool detect;
    return detect;
}

//F7 timeur
bool detect_temp(int time_x, int time_init)
{
    bool detect;
    return detect;
}

//F8 gestion Boussole
bool detect_angle(int angle)
{
    bool detect;
    return detect;
}

//F9 Autre
void perdu()
{

}

int temps_1m()
{
    //
    int time;
    return time;
}

void secur(int timemax)
{

}

//F10 Trajet

void base_chargement()
{
    //
}

void chargement_A()
{
    //
}

void chargement_B()
{
    //
}

void A_chargement()
{
    //
}

void B_chargement()
{
    //
}

void A_base()
{
    //
}

void B_base()
{
    //
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

    return 0;
}
