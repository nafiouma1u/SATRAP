#pragma once
#include "Aria.h"
#include "ArNetworking.h"
#include "ArClientHandlerRobotUpdate.h"
#include <vector>

public class RobotAdapteur
{
private:
	ArClientBase *client; //the base client class.
	ArClientSimpleConnector *connector;
	ArClientHandlerRobotUpdate *handUpdates;

	//functor is short for function pointer
	//ArFunctor1C, a functor which invokes a class method and takes one argument.
	//ArFunctor2C<RobotAdapter, const char *, const char *> cb; //functor pour la réception (et le traitement) d'update
	//void cb(const char *, const char *);
	//pas nécessaire ici

	char status[256];
	char mode[256];
	char *rStatus;

public:
	RobotAdapteur();
	~RobotAdapteur();

	void connect();
	void send(char *cmd, const char *data);
	bool isConnected();
	void goToDock();
	char* getStatus();
	void goToGoal(char goal[256]);
};

