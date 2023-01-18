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

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;	  // system_clock, seconds, milliseconds

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Début constantes
const int INT_MESURES = 100;
const int DEGRE_ANGLE_LIB = 10;
const int MAX_MESURES = 60;
// Fin constantes
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Début sous-programmes
void initCompas()
{
	int cpt;
	senseSetIMUConfig(true, true, true);
	for (cpt = 0; cpt < INT_MESURES; cpt++)
	{
		senseGetCompass();
	}
	cout << "initialisation faite" << endl;
}

bool detect_angle(double cap,double angle)
{
    double min,max;
	double save_val;

	bool inverse = false;

    min = cap - DEGRE_ANGLE_LIB;
    max = cap + DEGRE_ANGLE_LIB;
	save_val = max;

	cout<<min<<" "<<max<<" "<<inverse<<endl;

	// cas proche de 0 ou 360
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

	cout<<min<<" "<<max<<" "<<inverse<<endl;

	if (inverse)
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

double get_compas()
{
	return senseGetCompass();
}

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
		initCompas();
		cap = 1; //get_compas();
		for (cpt = 0; cpt < MAX_MESURES; cpt++)
		{
			compas = get_compas();
			cout << "Orientation de : " << compas << " degrés." << endl;
			if(detect_angle(cap,compas))
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