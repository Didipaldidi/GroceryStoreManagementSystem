#pragma once
#include "Include.h"

class Supplier
{
private:
	int id; // Primary Key
	string name;
	long int phn;
	string addr_line;
	string addr_city;
	string addr_state;

	MYSQL* conn;
	MYSQL_RES* res_set;
	MYSQL_ROW row;
	stringstream stmt;
	const char* q;
	string query;

public:
	Supplier(MYSQL* conn);
	string addSup();
	string removeSupplier();
	string searchId();
};

