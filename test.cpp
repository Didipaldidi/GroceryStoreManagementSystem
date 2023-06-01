#include "pch.h"
#include "gtest/gtest.h"
#include "C:/myProject/GroceyStoreManagement/Store/Product.h"
#include "C:/myProject/GroceyStoreManagement/Store/Product.cpp"
#include "C:/myProject/GroceyStoreManagement/Store/Supplier.cpp"
#include "C:/myProject/GroceyStoreManagement/Store/Supplier.h"
#include "C:/myProject/GroceyStoreManagement/Store/Purchase.cpp"
#include "C:/myProject/GroceyStoreManagement/Store/Purchase.h"

MYSQL* conn;

/*
TEST(Test_Product_Class, AddItem) {
	MYSQL* conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", "store", 3306, NULL, 0); //replace "password" with your sql server password

	Product p(conn);
	string res = p.add();
	EXPECT_TRUE("Pepper" == res || res == "Pepper");
}
TEST(Test_Product_Class, UpdatePrice) {
	MYSQL* conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", "store", 3306, NULL, 0); //replace "password" with your sql server password

	Product p(conn);
	string res = p.updatePrice();
	EXPECT_TRUE("1" == res || res == "1");
}
TEST(Test_Product_Class, SearchItem) {
	MYSQL* conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", "store", 3306, NULL, 0); //replace "password" with your sql server password

	Product p(conn);
	string res = p.search();
	EXPECT_TRUE("Soap" == res || res == "Soap");
}
TEST(Test_Supplier_Class, AddSupplier) {
	MYSQL* conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", "store", 3306, NULL, 0); //replace "password" with your sql server password

	Supplier s(conn);
	string res = s.addSup();
	EXPECT_TRUE("Sam" == res || res == "Sam");
}
TEST(Test_Supplier_Class, SearchSupplier) {
	MYSQL* conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", "store", 3306, NULL, 0); //replace "password" with your sql server password

	Supplier s(conn);
	string res = s.searchId();
	EXPECT_TRUE("Sam" == res || res == "Sam");
}
TEST(Test_Purchase_Class, PlaceNewOrder) {
	MYSQL* conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", "store", 3306, NULL, 0); //replace "password" with your sql server password

	Purchase pur(conn);
	string res = pur.newOrder();
	EXPECT_TRUE("5" == res || res == "5");
}
TEST(Test_Purchase_Class, MarkCancelOrder) {
	MYSQL* conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", "store", 3306, NULL, 0); //replace "password" with your sql server password

	Purchase pur(conn);
	string res = pur.markCancel();
	EXPECT_TRUE("C" == res || res == "C");
}
TEST(Test_Purchase_Class, MarkReceivedOrder) {
	MYSQL* conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", "store", 3306, NULL, 0); //replace "password" with your sql server password

	Purchase pur(conn);
	string res = pur.markReceived();
	EXPECT_TRUE("T" == res || res == "T");
}
*/