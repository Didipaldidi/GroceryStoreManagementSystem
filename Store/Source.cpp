#include "Product.h"
#include "Supplier.h"
#include "Purchase.h"

MYSQL* conn;


int main() {
	MYSQL* conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "password", "store", 3306, NULL, 0); //replace "password" with our sql server password


	Product pro(conn);

	//pro.add();
	//pro.display();
	//pro.updatePrice();
	//pro.display();
	//pro.search();

	Supplier sup(conn);

	//sup.addSup();
	//sup.searchId();

	Purchase pur(conn);
	pur.newOrder();
	pur.view();
	pur.markReceived();
	pur.view();
	pur.markCancel();
	pur.view();

	return 0;
}