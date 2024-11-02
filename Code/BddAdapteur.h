#pragma once
#include <iostream>
#include "windows.h"
#include "sqlext.h"
#include <sql.h>
#include <sqltypes.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "OperateurTransport.h"

class BddAdapteur {

private:
	SQLHENV henv;
	SQLHDBC hdbc;
	SQLHSTMT hstmt;

	SQLHSTMT hstm;

	int retcode;

public:
	BddAdapteur();
	void ExecRequete(char* Requete);
	float ReqDureeMoyenne();
	std::vector<OperateurTransport> RepNbrequete();

};