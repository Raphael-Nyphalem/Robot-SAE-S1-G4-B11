/* File: robot.cpp
 * Authors: Timothée Burgmeier & Raphaël Louis Le Denmat
 * Source: https://github.com/Raphael-Nyphalem/Robot-SAE-S1-G4-B11
 *
 *
 */

#include "robotmove.hpp"


namespace saeS1{

    void robot(double tabRobot[MAX_FONCTIONS][MAX_PARAMETRE])
    {
        for (int i = 0; i < MAX_FONCTIONS; i++)
        {
            execute_etape(tabRobot[i]); 
        }
    }

    //execute
    void execute_stop_0(double tabParametre[MAX_PARAMETRE])
    {
        while (tabParametre[1]!=0)
        {
            stop();
            tabParametre[1]=0;
        }
    }

    void execute_avanceValon_1(double tabParametre[MAX_PARAMETRE])
    {
        double cap = tabParametre[2];

        if (cap < 0 or cap > 360)
        {
            cap = get_compas();
        }
        
        do
        {
            tabParametre[1] = avance_valon(cap);
        } while (!detect_etape_en_cours(tabParametre));
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

        } while (!detect_etape_en_cours(tabParametre));
    }

    void execute_tourne_cap_3(double tabParametre[MAX_PARAMETRE])
    {
        double direction = tabParametre[2];

        do
        {
            tabParametre[1] = tourne_cap(direction);
            
        } while (!detect_etape_en_cours(tabParametre));
    }

    void execute_demit_tour_4(double tabParametre[MAX_PARAMETRE])
    {
        tabParametre[1]=0;

    }

    //selecteur etape
    void execute_etape (double tabRobot[MAX_PARAMETRE])
    {
        int fonction;
        fonction = tabRobot[0];

            switch (fonction)
            {
            case 0:
                execute_stop_0(tabRobot);
                break;

            case 1:
                execute_avanceValon_1(tabRobot);
                break;

            case 2:
                execute_avanceTempsCap_2(tabRobot);
                break;

            case 3:
                execute_tourne_cap_3(tabRobot);
                break;
            case 4:
                execute_demit_tour_4(tabRobot);
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

    /*
    void copie_etape(double tabParametre[MAX_PARAMETRE],double tabACopier[MAX_PARAMETRE])
    {
        for (int i = 0; i < MAX_PARAMETRE; i++)
        {
            tabParametre[i]=tabACopier[i];
        }
    }*/

    /*
    void init_tab_0(double tabRobot[MAX_FONCTIONS][MAX_PARAMETRE])
    {
        for (int f = 0; f < MAX_FONCTIONS; f++)
        {
            for (int p = 0; p < MAX_PARAMETRE; p++)
            {
                tabRobot[f][p]=0;
            } 
        }
    }
    */


} //namespace saeS1