#pragma once
#include <iostream>
#include <mysql.h>
#include <sstream>
#include <Windows.h>
#include <conio.h>
#include "Purchase.h"

using namespace std;
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
	void add();
	void updatePrice();
	void search();
	void update();
	void display();
};

