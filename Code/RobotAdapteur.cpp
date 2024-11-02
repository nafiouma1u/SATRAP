#include "RobotAdapteur.h"

void RobotAdapteur::connect()
{
	ArArgumentParser parser(new ArArgumentBuilder());
	//nullptr,nullptr); //du coup, pas de vérification d'arguments non supportés
	parser.loadDefaultArguments(); //normally, it first attempts a TCP connection on localhost port 8101, to use a simulator if running
	//parser.addDefaultArgument("-connectLaser");

	//gestion de la connexion réseau (paramètres dans parser)
	//par défaut, -host: localhost? (et idem port?)
	//this will let you connect to different hosts, ports, and with different users and passwords more easily.
	this->connector = new ArClientSimpleConnector(&parser);

	//tentative de connexion
	if (!this->connector->connectClient(client))
	{
		if (this->client->wasRejected())
			ArLog::log(ArLog::Normal, "Server '%s' rejected connection, exiting\n", this->client->getHost());
		ArLog::log(ArLog::Normal, "Error: Could not connect to robot... exiting");
		Aria::exit(1);
	}

	this->client->runAsync(); //run the cycle in a new background thread
	this->client->setRobotName(this->client->getHost()); //pour faciliter les logs
}

bool RobotAdapteur::isConnected()
{
	return this->client->isConnected();
}

void RobotAdapteur::send(char *cmd, const char *data)
{
	ArNetPacket p;
	p.strToBuf(data);
	this->client->requestOnce(cmd, &p);
}

RobotAdapteur::RobotAdapteur()
{
	Aria::init(); //perform global initialization

	this->client = new ArClientBase();
	this->connect();

	this->handUpdates = new ArClientHandlerRobotUpdate(this->client); //receives robot "update" responses from server and stores them.
	//addStatusChangedCB(ArFunctor2< const char *, const char * > *cb)
	this->handUpdates->requestUpdates(); // to begin receiving updates from the server, 100 ms par défaut
}

RobotAdapteur::~RobotAdapteur()
{
	this->handUpdates->stopUpdates();
	delete this->handUpdates;
	this->client->disconnect();
	delete this->connector;
	delete this->client;
	Aria::shutdown();
}

void RobotAdapteur::goToDock()
{
	this->send("dock", "Dock");
	ArUtil::sleep(1000);
}

char* RobotAdapteur::getStatus()
{
	rStatus = (char*)malloc(256 * sizeof(char));
	this->handUpdates->requestUpdates();
	strcpy(rStatus, this->handUpdates->getStatus());
	return rStatus;
}

void RobotAdapteur::goToGoal(char goal[256])
{
	this->send("gotoGoal", goal );
	ArUtil::sleep(1000);
};