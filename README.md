# GroceryStoreManagementSystem

## How to get Started
- For this project, you'll need to add mysql.h as an additional library directories
- You will also need to install and set up MySQL on your machine

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

## Directory Structure
This Solution has 2 projects, 1 is called GroceryStoreManagement and the second one is called Store. The first project was created for testing purposes using Google test however currently it is still empty. 
The store project is where the source code are. There are 3 classes (Product, Purchase, Supplier) each have their header file and cpp file and the Source.cpp
