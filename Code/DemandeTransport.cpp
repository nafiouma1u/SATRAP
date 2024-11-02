
#include "DemandeTransport.h"



DemandeTransport::DemandeTransport() {
	
	Robot = new RobotAdapteur();
	Bdd = new BddAdapteur();

	Bdd->ExecRequete("RequeteSQLNewdemande");
	
	Robot->goToGoal("Telma");




};

DemandeTransport::~DemandeTransport() {
	// Assurez-vous de libérer la mémoire allouée dynamiquement
	delete Robot;
	delete Bdd;
}