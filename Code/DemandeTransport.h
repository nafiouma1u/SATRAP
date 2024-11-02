#pragma once
#include "RobotAdapteur.h"
#include "BddAdapteur.h"



class DemandeTransport {
private:
	RobotAdapteur *Robot;
	BddAdapteur *Bdd; 
	
	
public:
	DemandeTransport();
	RobotAdapteur* getRobot() { return Robot; };
	BddAdapteur* getBdd() { return Bdd; };
	
	~DemandeTransport();
};