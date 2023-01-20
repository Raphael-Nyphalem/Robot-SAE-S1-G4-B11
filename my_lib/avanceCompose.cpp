/* File: capteur.cpp
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
        corrige l'angle en fonction a quelle point il est deporte de sa direction
        utilise
            - avance_Vitesse_Droit
            - avance_Vitesse_Gauche
            - get_angle
            - detect_angle
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
        

} //namespace saeS1