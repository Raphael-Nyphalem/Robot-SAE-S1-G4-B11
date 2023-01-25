/* File: tp8-ex1.cpp
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
	double compas, cap;
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
			cout << "Orientation de : " << compas << " degrés." << endl;
			if(detect_angle(cap))
			{
				cout << "Nous sommes dans le cap" << endl;
			}
			else 
			{
				cout << "Nous ne sommes pas dans le cap" << endl;
			}

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