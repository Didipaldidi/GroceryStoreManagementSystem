# GroceryStoreManagementSystem
The purpose of this project is to create an application where a store owner can manage it's inventory for their store. Some of the features in this project are:

**Product**
User can add new product, update it's price and inventory as well as view all existing products
**Supplier**
User can add new supplier for their store, search and remove a supplier
**Purchase**
User can place new order to restock their inventory, view all orders, mark existing order if they have been received or cancellled
## How to get Started
- For this project, you'll need to add mysql.h as an additional library directories
- You will also need to install and set up MySQL on your machine
- And for testing purposes, GoogleTest

## Project Structure
This project has 3 Classes each has it's own .cpp and .h file:
- Product
- Supplier
- Purchase

The **test.cpp** contain the test cases for this project, to run it just uncomment the codes in that file

## Setting up MySQL table
- DataBase Name : store
-> Product:
  - barcode int // Primary key
  - name varchar()
  - price int
  - qty int
 -> Suppliers:
  - sup_id int // Primary key
  - name varchar()
  - phone_n varchar()
  - addr_line varchar()
  - addr_city varchar()
  - addr_state varchar()
 -> Purchase:
  - ord_id int // Primary key
  - barcode int // Foreign key
  - sup_id int // Foreign key
  - qty int
  - dt_ordered int
  - eta int
  - received char(1) // check for 'F', 'T', or 'C' (Defaut 'F')
  - inv int
