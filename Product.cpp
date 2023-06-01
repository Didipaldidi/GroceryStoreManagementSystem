#include "Product.h"

Product::Product(MYSQL* conn) {
	this->conn = conn;
	if (this->conn) {
		puts("Successful connection to database from Product class!");
	}
	else {
		puts("connection to database failed");
	}
}

string Product::add() {
	cout << "Enter the barcode of the product : ";
	cin >> barcode;
	cout << "Enter the name of the product : ";
	cin >> name;
	cout << "Enter the Price : ";
	cin >> price;
	cout << "Enter the Qty Recived : ";
	cin >> qty;
	stmt.str("");
	stmt << "Insert into Product(barcode, name, price, qty) values('" << barcode << "','" << name << "'," << price << "," << qty << ");";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if (!(res_set))
		cout << endl << endl << "Product Record Inserted Successfully" << endl << endl << endl;
	else
		cout << endl << endl << "Entry ERROR !" << endl << "Contact Technical Team " << endl << endl << endl;
	stmt.str("");
	stmt << "Select name from product where barcode = " << barcode << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	row = mysql_fetch_row(res_set);
	string out = row[0];
	return out;
}

string Product::updatePrice()
{
	char choice;
	cout << "Enter the barcode for update in price : ";
	cin >> barcode;
	stmt.str("");
	stmt << "Select name,price from product where barcode = " << barcode << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "The Name of the product is : " << row[0] << endl;
		cout << "The current price of the product is : " << row[1] << endl;
		cout << "Do you Want to Update the Price [y/n] : ";
		cin >> choice;
		if (choice == 121 || choice == 89)
		{
			cout << "Enter the new price : ";
			cin >> price;
			stmt.str("");
			stmt << "UPDATE Product SET price = " << price << " WHERE barcode = " << barcode << ";";
			query = stmt.str();
			q = query.c_str();
			mysql_query(conn, q);
			res_set = mysql_store_result(conn);
			if (!(res_set))
				cout << endl << endl << "Product Price Updated Successfully" << endl << endl << endl;
			else
				cout << endl << endl << "Entry ERROR !" << endl << "Contact Technical Team " << endl << endl << endl;
		}
		else
		{
			cout << "No changes Made!!\n";
		}
	}
	else
	{
		cout << "No Book found!!!\n";
	}
	stmt.str("");
	stmt << "Select price from product where barcode = " << barcode << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	row = mysql_fetch_row(res_set);
	string out = row[0];
	return out;
}

void Product::display() {
	int i = 0;
	query = "Select * from Product;";
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	while ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "Barcode : " << row[0] << endl;
		cout << "Name of Product : " << row[1] << endl;
		cout << "Price : " << row[2] << endl;
		cout << "Quantity : " << row[3] << endl;
		cout << endl << endl << endl << endl;
	}
}

string Product::search() {
	cout << "Enter barcode for details : ";
	cin >> barcode;
	stmt.str("");
	stmt << "Select * from Product where barcode = " << barcode << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "The Product barcode: " << row[0] << endl;
		cout << "The Name of the product is : " << row[1] << endl;
		cout << "The Price of the product is : " << row[2] << endl;
		cout << "The inventory count is " << row[3] << endl;
	}
	else
	{
		cout << "No record Found" << endl;
	}
	stmt.str("");
	stmt << "Select name from product where barcode = " << barcode << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	row = mysql_fetch_row(res_set);
	string out = row[0];
	return out;
}

string Product::update() {
	int b_id[100], qty[100], i = 0, max;
	stmt.str("");
	stmt << "Select barcode,qty from purchase where received = 'T' and inv IS NULL;";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	stmt.str("");
	stmt << "Update purchase set inv = 1 where received = 'T' and inv IS NULL;";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	while ((row = mysql_fetch_row(res_set)) != NULL)
	{
		b_id[i] = (int)row[0];
		qty[i] = (int)row[1];
		i++;
	}
	max = i;
	for (i = 0; i <= max; i++)
	{
		stmt.str("");
		stmt << "update Product set qty = " << qty[i] << " where barcode = " << b_id[i] << ";";
		query = stmt.str();
		q = query.c_str();
		mysql_query(conn, q);
	}
	cout << "The orders recieved have been updated.";

	stmt.str("");
	stmt << "Select qty from product where barcode = " << barcode << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	row = mysql_fetch_row(res_set);
	string out = row[0];
	return out;
}