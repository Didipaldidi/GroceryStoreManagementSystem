#pragma once
#include "Include.h"

class Product
{
private:
	int barcode;// Primary Key
	string name;
	float price;
	int qty;

	MYSQL* conn;
	MYSQL_RES* res_set;
	MYSQL_ROW row;
	stringstream stmt;
	const char* q;
	string query;
public:
	Product(MYSQL* conn);
	string add();
	string updatePrice();
	string search();
	string update();
	void display();
};

