#pragma once
#include <string>


public class OperateurTransport {
private:
	int NbTransport;
	std::string NomOperateur;

public:
	void setNb(int a) { NbTransport = a; };
	void setNom(std::string b) { NomOperateur = b; };
	std::string getNom() const{ return NomOperateur; };
	int getNb() const{ return NbTransport; };
	
};


