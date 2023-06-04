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
    //w�acz grza�k� 
    cout << "heater on ";
    return true;
}

bool Heater::TurnOffHeater()
{
    // wy�acz grzanie
    cout << "heater off ";
    return false;
}

bool Heater::TurnOnFan()
{
    // w�acz ch�odzenie
    cout << "fan on ";
    return true;
}

bool Heater::TurnOffFan()
{
    // wy�acz ch�odzenie
    cout << "fan off ";
    return false;
}
