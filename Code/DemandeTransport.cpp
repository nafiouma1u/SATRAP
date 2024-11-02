
#include "DemandeTransport.h"



DemandeTransport::DemandeTransport() {
	
	Robot = new RobotAdapteur();
	Bdd = new BddAdapteur();

	Bdd->ExecRequete("RequeteSQLNewdemande");
	
	Robot->goToGoal("Telma");




};

DemandeTransport::~DemandeTransport() {
	// Assurez-vous de lib�rer la m�moire allou�e dynamiquement
	delete Robot;
	delete Bdd;
}