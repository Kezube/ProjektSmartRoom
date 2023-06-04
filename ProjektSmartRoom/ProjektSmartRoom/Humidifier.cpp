#include "Humidifier.h"
#include <iostream>
using namespace std;

Humidifier::Humidifier(double sp, double h, Fan* f) : fan(f)
{
    setPoint = sp;
    hysteresis = h;
    humidifierIsRunning = false;
    fanIsRunning = false;
}


void Humidifier::ChangeSetPoint(double sp)
{
    if(sp < 100 && sp > 0)
	    setPoint = sp;
}

void Humidifier::ChangeHysteresis(double h)
{
    if(h < 10 && h > 1)
	    hysteresis = h;
}

void Humidifier::CheckHumidity(double humidity)
{
    if (!humidifierIsRunning)
    {
        if (humidity <= setPoint - hysteresis)
        {
            humidifierIsRunning = TurnOnHumidifier();
        }
    }
    else
    {
        if (humidity > setPoint - hysteresis)
        {
            humidifierIsRunning = TurnOffHumidifier();
        }
    }
    if (!fanIsRunning)
    {
        if (humidity >= setPoint + hysteresis)
        {
            fanIsRunning = TurnOnFan();
        }
    }
    else
    {
        if (humidity < setPoint + hysteresis)
        {
            fanIsRunning = TurnOffFan();
        }
    }
}

bool Humidifier::TurnOnHumidifier()
{
    //w³acz nawilzacza 
    cout << "Humidifier on \n";
    return true;
}

bool Humidifier::TurnOffHumidifier()
{
    //wylacz nawilzacza 
    cout << "Humidifier off \n";
    return false;
}

bool Humidifier::TurnOnFan()
{
    // w³acz ch³odzenie
    fan->humidifierRequest = true;
    fan->VentilateRequest();
    return true;
}

bool Humidifier::TurnOffFan()
{
    // wy³acz ch³odzenie
    fan->humidifierRequest = false;
    fan->VentilateRequest();
    return false;
}

