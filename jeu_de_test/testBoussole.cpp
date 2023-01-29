/* File:
 * Author: Philippe Latu
 * Source: https://github.com/platu/libsensehat-cpp
 *
 * Patron du code source des séances de travaux pratiques
 */

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <string>

#include <sensehat.h>

#include "../my_lib/boussole.hpp"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;	  // system_clock, seconds, milliseconds

using namespace saeS1;


// Fin sous-programmes
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


int main()
{
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Début variables
	double compas, cap, oppo_cap;
	double min,max;
	bool inverse,inverse_oppo;
	int cpt;
	string direction;
	// Fin variables
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	if (senseInit())
	{
		cout << "Sense Hat initialization Ok." << endl;
		// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// Début instructions
		init_Compas();
		cap = 1; //get_compas();
		for (cpt = 0; cpt < 100; cpt++)
		{
			compas = get_compas();
			inverse = calcul_Min_Max(min,max,cap);
			inverse_oppo = calcul_Inverse_Cap(cap,oppo_cap);
			cout << "Orientation de : " << compas << " degrés." << endl;
			if(detect_angle(cap))
			{
				cout << "Nous sommes dans le cap" << endl;
				cout<<" le compas est bien entre "<< min <<" et "<< max <<endl;
			}
			else 
			{
				cout << "Nous ne sommes pas dans le cap" << endl;
				cout<<" le compas n'est pas entre "<< min <<" et "<< max <<endl;
			}
			cout<<"inverse ?: "<<inverse<< " opposer cap ? "<<oppo_cap<<" "<<inverse_oppo <<endl;

			sleep_for(milliseconds(200));
		}

		// Fin instructions
		// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		cout << "Press joystick button to quit." << endl;
		senseWaitForJoystickEnter();

		senseShutdown();
		cout << "Sense Hat shut down." << endl;
	}

	return EXIT_SUCCESS;
}
