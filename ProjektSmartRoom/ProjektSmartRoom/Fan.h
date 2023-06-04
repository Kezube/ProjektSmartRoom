#pragma once
class Fan
{
public:
	Fan();
	void VentilateRequest();
	
	bool heaterRequest;
	bool humidifierRequest;

private:
	bool fanIsRunning;
	bool Ventilate();
	bool StopVentilate();
	int x;


};

