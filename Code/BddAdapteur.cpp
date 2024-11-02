
#include "BddAdapteur.h"

BddAdapteur::BddAdapteur() {

	
	// Preparation du lien Application-ODBC 
	retcode = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);
	// ODBC V3 
	retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION,
		(void*)SQL_OV_ODBC3, 0);
	// Preparation d'une connexion 
	retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
	//Connexion 
	retcode = SQLConnect(hdbc,
		(unsigned char*)"bddsatrapNafiou", SQL_NTS,
		(unsigned char*)"peda", SQL_NTS,
		(unsigned char*)"SqlServer2019!", SQL_NTS);

}

void BddAdapteur::ExecRequete(char* Requete)
{
	

	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO)
	{
		//printf("Quelle misere ca marche pas!");
	}
	else
	{
		SQLLEN cbIdDemande = 0;
		char requete[256];
		char DateDebut[256];
		char statut[256];
		int IdDemandeTransport;
		
		//int IdOperateur;
		//printf("connexion reussie");
		// Allocation du handle pour le statement
		retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstm);
		if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO) {
			printf("Erreur lors de l'allocation du handle pour le statement.\n");
			//return 0 ;
		}

		// Execution de la requete pour obtenir le maximum de Iddemande
		retcode = SQLExecDirect(hstm, (unsigned char*)"SELECT MAX(IdDemandeTransport) FROM DemandeTransport", SQL_NTS);
		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
			SQLBindCol(hstm, 1, SQL_C_ULONG, &IdDemandeTransport, 0, &cbIdDemande);
			if (SQLFetch(hstm) == SQL_SUCCESS || SQLFetch(hstm) == SQL_SUCCESS_WITH_INFO) {
				//printf("\n MAX(IdDemandeTransport) = %d \n", IdDemandeTransport);
			}

			if (strcmp(Requete, "RequeteSQLNewdemande") != 1)
			{
				// Pr√©parez votre requ√™te SQL pour mettre √  jour le statut et r√©cup√©rer le CURRENT_TIMESTAMP
				IdDemandeTransport++;
				retcode = sprintf_s(requete, 200, "INSERT INTO DemandeTransport (IDdemandeTransport, DateDebut, IdOperateur, statut) VALUES (%d, CURRENT_TIMESTAMP, 1, 'prit en compte')", IdDemandeTransport);

				// Allocation du handle pour le statement
				retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
				if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO) {
					//std::cout << "Erreur lors de l'allocation du handle pour le statement." << std::endl;
					// G√©rer l'erreur ou quitter la fonction
					//return;
				}

				// Ex√©cution de la requ√™te SQL pour mettre √  jour le statut et r√©cup√©rer le CURRENT_TIMESTAMP
				retcode = SQLExecDirect(hstmt, (SQLCHAR*)requete, SQL_NTS);
				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
					//std::cout << "Statut mis √  jour avec succ√®s et DateFin r√©cup√©r√©e." << std::endl;
				}


			}
			
			else if (strcmp(Requete, "RequeteSQLUpdateDemande1") != 1)
			{

				retcode = sprintf_s(requete, 200, "UPDATE DemandeTransport SET statut = 'fin chargement' WHERE IdDemandeTransport = %d", IdDemandeTransport);

				retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
				if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO) {
					//std::cout << "Erreur lors de l'allocation du handle pour le statement." << std::endl;
					// G√©rer l'erreur ou quitter la fonction
					
				}

				// Ex√©cution de la requ√™te SQL pour mettre √  jour le statut
				retcode = SQLExecDirect(hstmt, (SQLCHAR*)requete, SQL_NTS);
				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
					//std::cout << "Statut mis √  jour avec succ√®s." << std::endl;
				}

				else {
					//std::cout << "Erreur lors de la mise √  jour du statut." << std::endl;
				}


				
			}
			else if (strcmp(Requete, "RequeteSQLUpdateDemande2") != 1) {
				// PrÈparez votre requÍte SQL pour mettre ‡ jour le statut et rÈcupÈrer le CURRENT_TIMESTAMP


				retcode = sprintf_s(requete, 200, "UPDATE DemandeTransport SET Statut = 'fin dechargement', DateFin = CURRENT_TIMESTAMP WHERE IDdemandeTransport = %d", IdDemandeTransport);

				// Allocation du handle pour le statement
				retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
				if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO) {
				//	std::cout << "Erreur lors de l'allocation du handle pour le statement." << std::endl;
					// GÈrer l'erreur ou quitter la fonction
					//return;
				}

				// ExÈcution de la requÍte SQL pour mettre ‡ jour le statut et rÈcupÈrer le CURRENT_TIMESTAMP
				retcode = SQLExecDirect(hstmt, (SQLCHAR*)requete, SQL_NTS);
				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
					//std::cout << "Statut mis ‡ jour avec succËs et DateFin rÈcupÈrÈe." << std::endl;
				}

			}
		}





	}

}


float BddAdapteur::ReqDureeMoyenne() {
	
	SQLDOUBLE DureeMoyenne = 0.0;
	// Allocation du handle pour le statement
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO) {
		//std::cout << "Erreur lors de l'allocation du handle pour le statement." << std::endl;
		//return;
	}

	// ExÈcution de la requÍte SQL pour calculer la durÈe moyenne en secondes entre DateDebut et DateFin
	retcode = SQLExecDirect(hstmt, (unsigned char*)"SELECT AVG(DATEDIFF(SECOND, DateDebut, DateFin)) AS DureeMoyenne FROM DemandeTransport;", SQL_NTS);
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO) {
		//std::cout << "Erreur lors de l'exÈcution de la requÍte pour calculer la durÈe moyenne." << std::endl;
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt); // LibÈrer le handle du statement
		//return;
	}

	// RÈcupÈration de la durÈe moyenne depuis le rÈsultat de la requÍte
	retcode = SQLBindCol(hstmt, 1, SQL_C_DOUBLE, &DureeMoyenne, sizeof(DureeMoyenne), NULL);
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO) {
	//	std::cout << "Erreur lors de la liaison de la colonne pour rÈcupÈrer la durÈe moyenne." << std::endl;
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt); // LibÈrer le handle du statement
		//return;
	}

	// ExÈcution de la requÍte SQL et rÈcupÈration des rÈsultats
	retcode = SQLFetch(hstmt);
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
		//printf("DurÈe moyenne : %.2f secondes\n", DureeMoyenne);
	}
	else {
		//std::cout << "Erreur lors de la rÈcupÈration de la durÈe moyenne." << std::endl;
	}

	SQLFreeHandle(SQL_HANDLE_STMT, hstmt); // LibÈrer le handle du statement aprËs utilisation


	
	return DureeMoyenne;
}

std::vector<OperateurTransport> BddAdapteur::RepNbrequete() {
	std::vector<OperateurTransport> operators;

	// Pr√©paration de la requ√™te SQL pour compter le nombre de demandes par IdOperateur
	SQLCHAR* query = (SQLCHAR*)"SELECT Operateur.IdOperateur, Operateur.Nom, Operateur.Prenom, COUNT(DemandeTransport.IdDemandeTransport) AS NombreDemandes "
		"FROM Operateur "
		"LEFT JOIN DemandeTransport ON Operateur.IdOperateur = DemandeTransport.IdOperateur "
		"GROUP BY Operateur.IdOperateur, Operateur.Nom, Operateur.Prenom";

	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

	// Ex√©cution de la requ√™te SQL
	retcode = SQLExecDirect(hstmt, query, SQL_NTS);


	
	SQLINTEGER idOperateur;
	SQLCHAR nom[256];
	SQLCHAR prenom[256];
	SQLINTEGER nombreDemandes;

	retcode = SQLBindCol(hstmt, 1, SQL_C_SLONG, &idOperateur, sizeof(idOperateur), NULL);
	retcode = SQLBindCol(hstmt, 2, SQL_C_CHAR, nom, sizeof(nom), NULL);
	retcode = SQLBindCol(hstmt, 3, SQL_C_CHAR, prenom, sizeof(prenom), NULL);
	retcode = SQLBindCol(hstmt, 4, SQL_C_SLONG, &nombreDemandes, sizeof(nombreDemandes), NULL);
	std::unordered_map<std::string, int> operatorRequestCounts;
	int i = 0;
	while (SQLFetch(hstmt) == SQL_SUCCESS) {
		operators.push_back(OperateurTransport());

		std::string name = std::string(reinterpret_cast<char*>(nom)); // Convert SQLCHAR to std::string
		int requests = static_cast<int>(nombreDemandes);

		OperateurTransport operatorObj;

		operatorObj.setNom(std::string(reinterpret_cast<char*>(nom))); // Utilisation du setter pour le nom
		operatorObj.setNb(static_cast<int>(nombreDemandes)); // Utilisation du setter pour NbTransport


		// Vous pouvez ajouter l'objet OperateurTransport directement au vecteur
		operators.push_back(operatorObj);

		// Check if the operator's name already exists in the map
		if (operatorRequestCounts.find(name) == operatorRequestCounts.end()) {
			operatorRequestCounts[name] = requests;
		}
		else {
			operatorRequestCounts[name] += requests;
		}

		
		
	}
	
	return operators; 
}



