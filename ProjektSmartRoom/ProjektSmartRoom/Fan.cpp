#include "Fan.h"
#include <iostream>
using namespace std;

Fan::Fan()
{
	fanIsRunning = false;
	heaterRequest = false;
	humidifierRequest = false;
}

void Fan::VentilateRequest()
{
	if (!fanIsRunning)
	{
		if (heaterRequest == true || humidifierRequest == true )
		{
			fanIsRunning = Ventilate();
		}
	}
	else
	{
		if (heaterRequest == false && humidifierRequest == false)
		{
			fanIsRunning = StopVentilate();
		}
	}
}

bool Fan::Ventilate()
{
	// Uruchom fyrtok
	cout << "fyrtok on \n";
	return true;
}

bool Fan::StopVentilate()
{
	// zatrzym fyrtok
	cout << "fyrtok off \n";
	return false;
}
