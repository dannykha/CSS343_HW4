# CSS343_HW4
Assignment 4: Movie Rental Store

created by Andrew Demaris, Danny Kha, and Sara Saleh

Contribution of each group member

Andrew:

Danny:

Sara:

Completed: June _, 2022

### Overview:
The ... //add more here to describe overall implementation

The rental store uses the following classes:
- Store -  holds the functions to read data files and initialize the store, customers, and movies

- HashTable - data structure to hold customer data

- Customer - holds the functions to initialize each customer, and the action commands per customer
    - Borrow - denoted as "B", subtracts 1 from stock
    - Return - denoted as "R", adds 1 to stock
    - Inventory - prints complete store inventory 
    - History - prints customer transaction history
    
- CustomerDataBase - implements a hash table to record each customer by their ID number, name
    
- Movie - class that uses inheritance for each of its child classes for each movie genre
    - Comedy - denoted as "F"
    - Drama - denoted as "D"
    - Classic - denoted as "C"