/* File: avanceCompose.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *
 */

#include "avanceCompose.hpp"



namespace saeS1{


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


} //namespace saeS1