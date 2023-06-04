#pragma once
#include "Fan.h"
class Humidifier
{
public:
	Humidifier(double sp, double h, Fan* f);
	void ChangeSetPoint(double sp);
	void ChangeHysteresis(double h);
	void CheckHumidity(double t);

private:
	double setPoint;
	double hysteresis;
	bool humidifierIsRunning;
	bool fanIsRunning;
	Fan* fan;

	bool TurnOnHumidifier();
	bool TurnOffHumidifier();
	bool TurnOnFan();
	bool TurnOffFan();



};

