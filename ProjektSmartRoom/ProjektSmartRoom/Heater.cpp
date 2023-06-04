#include "Heater.h"
#include <iostream>
using namespace std;

Heater::Heater(double sp, double h, Fan* fan) : fan(fan)
{
	setPoint = sp;
	hysteresis = h;
    heaterIsRunning = false;
    fanIsRunning = false;
}


void Heater::ChangeSetPoint(double sp)
{
    if (sp > 10 && sp < 30)
        setPoint = sp;
}
    
	

void Heater::ChangeHysteresis(double h)
{
    if (h > 1 && h < 10)
        hysteresis = h;
}

void Heater::CheckTemperature(double temperature)
{
    if (!heaterIsRunning) 
    {
        if (temperature <= setPoint - hysteresis)
        {
            heaterIsRunning = TurnOnHeater();
        }
    }
    else
    {
        if (temperature > setPoint - hysteresis) 
        {
            heaterIsRunning = TurnOffHeater();
        }
    }
    if (!fanIsRunning)
    {
        if (temperature >= setPoint + hysteresis)
        {
            fanIsRunning = TurnOnFan();
        }
    }
    else
    {
        if (temperature < setPoint + hysteresis)
        {
            fanIsRunning = TurnOffFan();
        }
    }

}

bool Heater::TurnOnHeater()
{
    //w³acz grza³kê 
    cout << "heater on \n";
    return true;
}

bool Heater::TurnOffHeater()
{
    // wy³acz grzanie
    cout << "heater off \n";
    return false;
}

bool Heater::TurnOnFan()
{
    // w³acz ch³odzenie
    fan->heaterRequest = true;
    fan->VentilateRequest();
    return true;
}

bool Heater::TurnOffFan()
{
    // wy³acz ch³odzenie
    fan->heaterRequest = false;
    fan->VentilateRequest();
    return false;
}
