
#include <iostream>
#include "Heater.h"
#include "Humidifier.h"

int main()
{
    Fan fan;
    Heater heater(20, 5, &fan);
    Humidifier humidifier(30, 5, &fan);
  
    for (size_t i = 0; i < 50; i++)
    {
        std::cout << i << "\t";
        heater.CheckTemperature(i);
        humidifier.CheckHumidity(i);
        std::cout << "\n";
    }
    for (size_t i = 0; i < 50; i++)
    {
        std::cout << 50-i << "\t";
        heater.CheckTemperature(50-i);
        humidifier.CheckHumidity(50-i);
        std::cout << "\n";
    }
    std::cout << "\n";
    heater.ChangeSetPoint(30);
    heater.ChangeHysteresis(7);
    humidifier.ChangeSetPoint(20);
    humidifier.ChangeHysteresis(2);
    for (size_t i = 0; i < 50; i++)
    {
        std::cout << i << "\t";
        heater.CheckTemperature(i);
        humidifier.CheckHumidity(i);
        std::cout << "\n";
    }
    for (size_t i = 0; i < 50; i++)
    {
        std::cout << 50 - i << "\t";
        heater.CheckTemperature(50 - i);
        humidifier.CheckHumidity(50 - i);
        std::cout << "\n";
    }


}
