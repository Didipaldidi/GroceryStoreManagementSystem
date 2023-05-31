#pragma once
#include "Product.h"

class Purchase
{
private:
	int ordId;
	int barcode; //Foreign key Product->barcode
	int supId; // Foreign key Suppliers->id
	int qty;
	DATE dt_ordered;
	int eta;
	char received; // Check T or C or F) default (F)
	int inv;

	MYSQL* conn;
	MYSQL_RES* res_set;
	MYSQL_ROW row;
	stringstream stmt;
	const char* q;
	string query;
public:
	Purchase(MYSQL* conn);
	void newOrder();
	void view();
	void markCancel();
	void markReceived();
};

