/* File: robot.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *
 */

#include "robot.hpp"


namespace saeS1{

    void robot(int tabRobot[MAX_FONCTIONS][MAX_PARAMETRE])
    {
        int fonction;
        for (int i = 0; i < MAX_FONCTIONS; i++)
        {
            fonction = tabRobot[i][0];

            switch (fonction)
            {
            case 0:
                stop();
                break;
            
            default:
                break;
            }
        }
        
    }


} //namespace saeS1