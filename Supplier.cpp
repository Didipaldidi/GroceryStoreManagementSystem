#include "Supplier.h"

Supplier::Supplier(MYSQL* conn) {
	this->conn = conn;

	if (this->conn) {
		puts("Successful connection to database from Suppliers class!");
	}
	else {
		puts("connection to database failed");
	}
}

string Supplier::addSup() {
	cout << "Enter the supplier Id: ";
	cin >> id;
	cout << "Enter the Supplier Name : ";
	cin >> name;
	cout << "Enter Phone no. : ";
	cin >> phn;
	cout << "Enter the Address : ";
	cin >> addr_line;
	cout << "Enter the City : ";
	cin >> addr_city;
	cout << "Enter State : ";
	cin >> addr_state;
	stmt.str("");
	stmt << "Insert into Suppliers(id, name,phone_n,addr_line,addr_city,addr_state) values("<< id << ",'" << name << "', '" << phn << "', '" << addr_line << "', '" << addr_city << "', '" << addr_state << "');";		
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if (!(res_set))
		cout << endl << endl << "Supplier Record Inserted Successfully" << endl << endl << endl;
	else
		cout << endl << endl << "Entry ERROR !" << endl << "Contact Technical Team " << endl << endl << endl;

	stmt.str("");
	stmt << "Select name from suppliers where id = " << id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	row = mysql_fetch_row(res_set);
	string out = row[0];
	return out;
}

string Supplier::searchId() {
	cout << "Enter the supplier id to find the Supplier details : ";
	cin >> id;
	stmt.str("");
	stmt << "Select * from suppliers where id = " << id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "Details of Supplier Id : " << row[0] << endl;
		cout << "Name : " << row[1] << endl;
		cout << "Phone no. : " << row[2] << endl;
		cout << "Address Line 1 : " << row[3] << endl;
		cout << "City : " << row[4] << endl;
		cout << "State : " << row[5] << endl;
	}
	else
	{
		cout << "No Supplier Found!!";
	}
	stmt.str("");
	stmt << "Select name from suppliers where id = " << id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	row = mysql_fetch_row(res_set);
	string out = row[0];
	return out;
}

string Supplier::removeSupplier() {
	cout << "Enter the supplier id to remove the Supplier : ";
	cin >> id;
	stmt.str("");
	stmt << "Delete from suppliers where id = " << id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	cout << "Supplier Removed.";
}