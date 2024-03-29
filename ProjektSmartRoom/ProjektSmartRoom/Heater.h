#pragma once
#include "Fan.h"
class Heater
{
public:
	Heater(double sp, double h, Fan* fan);
	void ChangeSetPoint(double sp);
	void ChangeHysteresis(double h);
	void CheckTemperature(double t);


private:
	double setPoint;
	double hysteresis;
	bool heaterIsRunning;
	bool fanIsRunning;
	Fan* fan;

	bool TurnOnHeater();
	bool TurnOffHeater();
	bool TurnOnFan();
	bool TurnOffFan();

};

