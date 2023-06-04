#include "Heater.h"
#include <iostream>
using namespace std;

Heater::Heater(double sp, double h)
{
	setPoint = sp;
	hysteresis = h;
    heaterIsRunning = false;
    fanIsRunning = false;
}

void Heater::ChangeSetPoint(double sp)
{
	setPoint = sp;
}

void Heater::ChangeHysteresis(double h)
{
	hysteresis = h;
}

void Heater::CheckTemperature(double t)
{
    if (!heaterIsRunning) 
    {
        if (t <= setPoint - hysteresis)
        {
            heaterIsRunning = TurnOnHeater();
        }
    }
    else
    {
        if (t > setPoint - hysteresis) 
        {
            heaterIsRunning = TurnOffHeater();
        }
    }
    if (!fanIsRunning)
    {
        if (t >= setPoint + hysteresis)
        {
            fanIsRunning = TurnOnFan();
        }
    }
    else
    {
        if (t < setPoint + hysteresis)
        {
            fanIsRunning = TurnOffFan();
        }
    }

}

bool Heater::TurnOnHeater()
{
    //w³acz grza³kê 
    cout << "heater on ";
    return true;
}

bool Heater::TurnOffHeater()
{
    // wy³acz grzanie
    cout << "heater off ";
    return false;
}

bool Heater::TurnOnFan()
{
    // w³acz ch³odzenie
    cout << "fan on ";
    return true;
}

bool Heater::TurnOffFan()
{
    // wy³acz ch³odzenie
    cout << "fan off ";
    return false;
}
