/* File: avanceCompose.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *
 */



#include "avanceCompose.hpp"


using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // system_clock, seconds, milliseconds

namespace saeS1{

    // init
    
    void init()
    {
        std::cout << "~~debut init~~\n";
        init_gpio_capteur();
        init_Compas();
        init_gpio_moteur();
        std::cout << "~~fin init~~\n";
    }

    //fontion interne

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
                }
                else if ((angle < min) && angle > nonCap)
                {
                    avance_Vitesse_Gauche(VITESSE_4);
                    avance_Vitesse_Droit(0);
                }
            }
            else 
            {
                if ((angle < min) || (angle > nonCap))
                {
                    avance_Vitesse_Gauche(VITESSE_4);
                    avance_Vitesse_Droit(0);
                } 
                else if((angle > max) && (angle < nonCap))
                {
                    avance_Vitesse_Gauche(0);
                    avance_Vitesse_Droit(VITESSE_4);
                }
            }
            
        }
        //std::cout << min << " " << max << "| angle: " << angle<<"| cap: "<<angle_cap<< "| non cap: "<<nonCap <<endl;
    }

    void avance_Cap(double cap)
    {
        /*
        Avance en direction d'un cap donnez
        utilise
            - detect_angle
            - avance_vit
            - correction_angle
        */
       if(detect_angle(cap))
        {
            avance_vit(VITESSE_ROBOT);
        }
        else
        {
            correction_angle(cap);
        }
    }

    bool avance_valon(double cap)
    {
        /*
        Avance tout droit jusqu'a un valon
        Renvoie vrais lorsque on est en mouvement
        utilise
            - avance_cap
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
            avance_Cap(cap)
            return true;
        }
    
    }

    //fonction de déplacement

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
            stop();
            return false;
        }
        else
        {
            avance_Cap(cap);
            return true;
        }
        return false;
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

} //namespace saeS1