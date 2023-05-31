#include "Purchase.h"

Purchase::Purchase(MYSQL* conn) {
	this->conn = conn;

	if (this->conn) {
		puts("Successful connection to database from Purchase class!");
	}
	else {
		puts("connection to database failed");
	}
}

void Purchase::newOrder() {
	cout << "Enter the order number: ";
	cin >> ordId;
	cout << "Enter the Product barcode : ";
	cin >> barcode;
	cout << "Enter Supplier Id : ";
	cin >> supId;
	cout << "Enter the Quantity : ";
	cin >> qty;
	cout << "Estimated expected Delivery (in days) : ";
	cin >> eta;
	stmt.str("");
	stmt << "Insert into purchase (ord_id,barcode,sup_id,qty,dt_ordered,eta) values ( "<< ordId<< "," << barcode << "," << supId << "," << qty << ", CURDATE(), DATE_ADD(CURDATE(), INTERVAL " << eta << " DAY))" << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	cout << "New order Added!!\n";
}

void Purchase::markCancel() {
	cout << "Enter the order id for order cancelled : ";
	cin >> ordId;
	stmt.str("");
	stmt << "Update puchase set received = 'C' where ord_id = " << ordId << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	cout << "Cancelled Marked successfully\n";
}

void Purchase::markReceived() {
	cout << "Enter the order id for order recieved : ";
	cin >> ordId;
	stmt.str("");
	stmt << "Update puchase set received = 'T' where ord_id = " << ordId << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	cout << "Recieved Marked successfully\n";
}

void Purchase::view() {
	int c;
	cout << "Select an Option" << endl;
	cout << "1. View orders not Recieved" << endl;
	cout << "2. View orders Cancelled" << endl;
	cout << "3. View orders Recieved" << endl;
	cout << "Enter Your choice : ";
	cin >> c;
	if (c == 1)
		received = 'F';
	else if (c == 2)
		received = 'C';
	else if (c == 3)
		received = 'T';
	else
		return;
	stmt.str("");
	stmt << "Select * from purchase where received = '" << received << "';";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if (c == 1)
		cout << endl << "Orders not recieved are" << endl;
	else if (c == 2)
		cout << endl << "Orders Cancelled are" << endl;
	else if (c == 3)
		cout << endl << "Orders recieved are" << endl;
	while ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << endl;
		cout << "Order Id : " << row[0] << endl;
		cout << "Barcode : " << row[1] << endl;
		cout << "Supplier Id :" << row[2] << endl;
		cout << "Quantity : " << row[3] << endl;
		cout << "Date Ordered : " << row[4] << endl;
		cout << "Estimated Delivery date : " << row[5] << endl;
		cout << endl << endl << endl;
	}
	cout << endl << endl << endl << endl << endl;
}