#pragma once
class Heater
{
public:
	Heater(double sp, double h);
	void ChangeSetPoint(double sp);
	void ChangeHysteresis(double h);
	void CheckTemperature(double t);


private:
	double setPoint;
	double temperature;
	double hysteresis;
	bool heaterIsRunning;
	bool fanIsRunning;

	bool TurnOnHeater();
	bool TurnOffHeater();
	bool TurnOnFan();
	bool TurnOffFan();

};

