/* File: avanceCompose.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *
 */

#include <iostream>


using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;	  // system_clock, seconds, milliseconds

void init();

    void correction_angle
    (
        double angle_cap
    );

    void avance_Cap
    (
        double cap
    );

    bool avance_valon
    (
        unsigned int vit
    );

    bool avance_temps_cap
    (
        double temps, 
        double cap, 
        temps_t temps0
    );

    bool tourne_cap
    (
        double angle_tourne
    );

const int INT_MESURES = 100;
    const int DEGRE_ANGLE_LIB = 10;

    void init_Compas();

    double get_compas();

    bool calcul_Min_Max 
    (
        double &min,
        double &max,
        double cap
    );

    bool detect_angle
    (
        double cap
    );
    
    bool calcul_Inverse_Cap
    (
        double cap,
        double &nonCap
    );

    double calcul_Nouveau_Cap
    (
        double direction
    );

    const unsigned int PIN_CAPT_GAUCHE = 16;
    const unsigned int PIN_CAPT_DROIT= 17;
    
    void 
    init_gpio_capteur();

    bool 
    detec_Capt_Droit();

    bool 
    detec_Capt_Gauche();

    bool 
    detec_2_Capt();

    const unsigned int CHAN_MOT_GAUCHE = 0;
    const unsigned int CHAN_MOT_DROIT= 1;
    const unsigned int PERIODE_MS = 10000;


    const int VITESSE_0 = 0;
    const int VITESSE_1 = 25;
    const int VITESSE_2 = 50;
    const int VITESSE_3 = 75;
    const int VITESSE_4 = 100;

    void 
    init_gpio_moteur();

 
    void 
    avance_Vitesse_Droit(
            unsigned int vit
            );

    void 
    avance_Vitesse_Gauche(
            unsigned int vit
            );

    void 
    avance_vit(
            unsigned int vit
            );

    void 
    stop_Mot_Gauche();

    void 
    stop_Mot_Droit();

    void 
    stop();

    const int MAX_FONCTIONS = 30;
    const int MAX_PARAMETRE = 6;

    
    void robot
    (
        double tabRobot[MAX_FONCTIONS][MAX_PARAMETRE]
    );

    void execute_stop_0
    (
        double tabParametre[MAX_PARAMETRE]
    );

    void execute_avanceValon_1
    (
        double tabParametre[MAX_PARAMETRE]
    );

    void execute_avanceTempsCap_2
    (
        double tabParametre[MAX_PARAMETRE]
    );

    void execute_tourne_cap_3
    (
        double tabParametre[MAX_PARAMETRE]
    );
    
    void execute_etape 
    (
        double tabParametre[MAX_PARAMETRE]
    );

    bool detect_etape_en_cours
    (
        double tabParametre[MAX_PARAMETRE]
    );

    void edit_etape
    (
        double tabParametre[MAX_PARAMETRE]
    );

    void copie_etape
    (
        double tabParametre[MAX_PARAMETRE],
        double tabACopier[MAX_PARAMETRE]
    );

    void affiche_etape
    (
        double tabParametre[MAX_PARAMETRE]
    );

    void init_tab_0
    (
        double tabRobot[MAX_FONCTIONS][MAX_PARAMETRE]
    );

    typedef struct{
        std::chrono::steady_clock::time_point t;
    }temps_t;

void get_temps(
    temps_t &temps
    );

double temps_Passe(
    temps_t &temps0
    );

bool detect_temps(
    double tempsSeuil,
    temps_t &temps0);





    void init()
    {
        std::cout << "~~debut init~~\n";
        init_gpio();
        init_Compas();
        init_gpio_moteur();
        std::cout << "~~fin init~~\n";
    }

    void correction_angle(double angle_cap)
    {
        /*
        corrige la trajectoire du robot en direction du cap
        utilise
            - avance_Vitesse_Droit
            - avance_Vitesse_Gauche
            - get_compas
            - calcul_Inverse_Cap
            - calcul_Min_Max
        */
        double min,max;
        double angle;
        double nonCap;

        angle = get_compas();

        if (calcul_Min_Max(min,max,angle_cap))
        {
            //cas inversé
            if(angle > min && angle < 180)
            {
                avance_Vitesse_Gauche(VITESSE_1);
                avance_Vitesse_Droit(VITESSE_4);
            }
            else if (angle < max &&  angle > 180 )
            {
                avance_Vitesse_Gauche(VITESSE_4);
                avance_Vitesse_Droit(VITESSE_1);
            }
        }
        else
        {
            //cas non inversé
            //On prends en compte que la boussole fonctionne en sens horraire
            if(calcul_Inverse_Cap(angle_cap, nonCap))
            {
                if((angle > max) || angle < nonCap)
                {
                    avance_Vitesse_Gauche(0);
                    avance_Vitesse_Droit(VITESSE_4);
                    cout << "droite\n";
                }
                else if ((angle < min) && angle > nonCap)
                {
                    avance_Vitesse_Gauche(VITESSE_4);
                    avance_Vitesse_Droit(0);
                    cout << "gauche\n";
                }
            }
            else 
            {
                if ((angle < min) || (angle > nonCap))
                {
                    avance_Vitesse_Gauche(VITESSE_4);
                    avance_Vitesse_Droit(0);
                    cout << "droite\n";
                } 
                else if((angle > max) && (angle < nonCap))
                {
                    avance_Vitesse_Gauche(0);
                    avance_Vitesse_Droit(VITESSE_4);
                    cout << "gauche\n";
                }
            }
            
        }
        //cout << min << " " << max << "| angle: " << angle<<"| cap: "<<angle_cap<< "| non cap: "<<nonCap <<endl;
    }

    void avance_Cap(double cap)
    {
        /*
        Avance en direction d'un cap donnez
        utilise
            - detect_angle
            - avance_valon
            - correction_angle
        */
       if(detect_angle(cap))
        {
            avance_valon(VITESSE_4);
        }
        else
        {
            correction_angle(cap);
        }
    }

    bool avance_valon(unsigned int vit)
    {
        /*
        Avance tout droit jusqu'a un valon a une vitesse donné
        Renvoie vrais lorsque on est en mouvement
        utilise
            - avance_vit
            - detec_2_Capt
            - stop
        */
        if (detec_2_Capt())
        {
            stop();
            return false;
        }
        else
        {
            avance_vit(vit);
            return true;
        }
    
    }
        
    bool avance_temps_cap(double temps, double cap, temps_t temps0)
    {
        /*
        Avance tout droit 
            en direction d'un cap donnez
            durant un temps donnez
        Renvoie vrais lorsque on est en mouvement
        utilise
            - avance_vit
            - detec_2_Capt
            - stop
        */
        if (detect_temps(temps,temps0))
        {
            avance_Cap(cap);
            return true;
        }
        else
        {
            stop();
            return false;
        }
    }

    bool tourne_cap(double angle_tourne)
    {
        double cap = calcul_Nouveau_Cap(angle_tourne);
        if (detect_angle(cap))
        {
            stop();
            return false;
        }
        else
        {
            correction_angle(cap);
            return true;
        }
    }
void init_Compas()
    {
        /*
        Permet d'optenir d'initialiser la boussole
        utilise
        <sensehat.h>
        get_compas()
        */
        int cpt;
        senseSetIMUConfig(true, true, true);
        for (cpt = 0; cpt < INT_MESURES; cpt++)
        {
            senseGetCompass();
        }
        cout << "initialisation faite" << endl;
    }

    double get_compas()
    {
        /*
        Permet d'optenir l'angle actuel de la boussole
        utilise
        <sensehat.h>
        */
        return senseGetCompass();
    }

    bool calcul_Min_Max (double &min,double &max,double cap)
    {
        /*
        Permet de calculer une plage autour du cap a suivre MIN, MAX
        Prend en compte lorsque le cap est proche de 0 grave a la varible inverse
        Renvoie vrais lorsque on est dans le cas inverse
        */
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

    bool calcul_Inverse_Cap(double cap, double &nonCap)
    {
        /*
            Permet de calculer l'angle opposé au cap
            Renvoie vrai si le cap est supérieur à 180 et calcule l'opposé du cap.
        */
        if(cap < 180)
        {
            nonCap = cap+180;
            return false;
        }
        else
        {
            nonCap = cap-180;
            return true;
        }
    }

    double calcul_Nouveau_Cap(double direction)
    {
        double cap = get_compas();

        double nouveauCap;

        if((cap + direction)<0)
        {
            nouveauCap = cap + direction + 360;
        }
        else if ((cap + direction)>360)
        {
            nouveauCap = cap + direction - 360;
        }
        else
        {
           nouveauCap = cap + direction;
        }
        return nouveauCap;
        
    }

    bool detect_angle(double cap)
    {
        /*
        Permet de détecter si le sensor (ou le robot dans notre cas)
        est dans le cap 
        utilise
        get_compas()
        calcul_Min_Max()

        */
        double angle;
        double min,max;

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
    void init_gpio_capteur()
    {
        /*
        Permet d'optenir d'initialiser les pins des capteurs gpios
        utilise
        gpio rapsberry
        */
        gpioSetConfig(PIN_CAPT_GAUCHE, in);
        gpioSetConfig(PIN_CAPT_DROIT, in);
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

    void init_gpio_moteur()
    {
        /*
        Permet d'optenir d'initialiser 
        les channel des moteurs
        leur applique une période
        stop les moteur a l'init
        utilise
        gpio rapsberry
        */
        pwmInit(CHAN_MOT_DROIT);
        pwmPeriod(CHAN_MOT_DROIT, PERIODE_MS);
        pwmDutyCycle(CHAN_MOT_DROIT,0);
        pwmEnable(CHAN_MOT_DROIT);

        pwmInit(CHAN_MOT_GAUCHE);
        pwmPeriod(CHAN_MOT_GAUCHE, PERIODE_MS);
        pwmDutyCycle(CHAN_MOT_GAUCHE,0);
        pwmEnable(CHAN_MOT_GAUCHE);
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
        */
        avance_Vitesse_Droit(vit);
        avance_Vitesse_Gauche(vit);
    
    }

    void stop_Mot_Gauche()
    {
        /*
        arret du moteur Gauche
        utilise 
            gpio raspberry
        */
        pwmDutyCycle(CHAN_MOT_GAUCHE,0);
    }

    void stop_Mot_Droit()
    {
        /*
        arret du moteur Gauche
        utilise 
            gpio raspberry
        */
        pwmDutyCycle(CHAN_MOT_DROIT,0);
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

    int main() {
        return EXIT_SUCCESS;
    }

    void get_temps(temps_t &temps)
    {
        /*
        Recupère l'heure de la machine
        utilise
            <chrono>
        */
        temps.t = steady_clock::now();
    }

    double temps_Passe(temps_t &temps0)
    {
        /*
        calcul la difference de temps entre un temps0 et le temps actuel de la machine
        utilise
            <chrono>
            get_temps
        */
        temps_t tempsActuel;
        get_temps(tempsActuel);

        duration<double> temps_diff = duration_cast<duration<double>>(tempsActuel.t-temps0.t);
        return temps_diff.count();
    }

    bool detect_temps(double tempsSeuil,temps_t &temps0)
    {
        /*
        Detecte lorsque la difference de temps (entre un temps0 et le temps actuel de la machine) 
        est supperieur a un seuil
        Renvoie vrais lorsque ce temps est supperieur au seuil
        utilise
            temps_Passe
        */
        if (temps_Passe(temps0) >= tempsSeuil)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void robot(double tabRobot[MAX_FONCTIONS][MAX_PARAMETRE])
    {
        double fonction;
        for (int i = 0; i < MAX_FONCTIONS; i++)
        {
            execute_etape(tabRobot[i]); 
        }
    }

    //execute
    void execute_stop_0(double tabParametre[MAX_PARAMETRE])
    {
        stop();
        tabParametre[1]=0;
    }

    void execute_avanceValon_1(double tabParametre[MAX_PARAMETRE])
    {
        int vit = tabParametre[2];
        do
        {
            tabParametre[1] = avance_valon(vit);
        } while (detect_etape_en_cours(tabParametre[1]));
    }

    void execute_avanceTempsCap_2(double tabParametre[MAX_PARAMETRE])
    {
        double temps = tabParametre[2];
        double cap = tabParametre[3];
        
        temps_t  temps0;
        get_temps(temps0);

        if (cap < 0 or cap > 360)
        {
            cap = get_compas();
        }
        do
        {
            tabParametre[1] = avance_temps_cap(temps,cap,temps0);

        } while (detect_etape_en_cours(tabParametre[1]));
    }

    void execute_tourne_cap_3(double tabParametre[MAX_PARAMETRE])
    {
        double direction = tabParametre[2];

        do
        {
            tabParametre[1] = tourne_cap(direction);
            
        } while (detect_etape_en_cours(tabParametre[1]));
        

    }

    //selecteur etape
    void execute_etape (double tabParametre[MAX_PARAMETRE])
    {
        int fonction;
        fonction = tabRobot[0];

        switch (fonction)
        {
            case 0:
                execute_stop_0(tabParametre)
            break;

            case 1:
                execute_avanceValon_1(tabParametre)
            break;

            case 2:
                execute_avanceTempsCap_2(tabParametre)
            break;

            case 3:
                execute_tourne_cap_3(tabParametre)
            break;

            default:
            break;
        }

    }

    bool detect_etape_en_cours(double tabParametre[MAX_PARAMETRE])
    {
        if (tabParametre[1]==0)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

    void edit_etape(double tabParametre[MAX_PARAMETRE])
    {

    }

    void copie_etape(double tabParametre[MAX_PARAMETRE],double tabACopier[MAX_PARAMETRE])
    {
        
    }

    void affiche_etape(double tabParametre[MAX_PARAMETRE])
    {
        
    }

    void init_tab_0(double tabRobot[MAX_FONCTIONS][MAX_PARAMETRE])
    {
        for (int f = 0; f < MAX_FONCTIONS; f++)
        {
            for (int p = 0; p < count; p++)
            {
                tabRobot[f][p]=0;
            } 
        }
    }

