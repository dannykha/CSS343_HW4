# CSS343_HW4
Assignment 4: Movie Rental Store

Created by: Andrew Demaris, Danny Kha, and Sara Saleh

Contribution of each group member:
We did pair-programming and rotated partners. Thus, it's difficult to determine the explicit contributions
 of each inidividual group member. We all contributed equally to different degrees of each file and class.

Created: May 18, 2022

Completed: June 8, 2022

### Overview:
The StoreBuilder class initializes the Store object. In Store, the customers, movies, and commands are
 initialized. Customer data is stored in CustomerDatabase while movies are stored in MovieInventory;
 the Customer and Movie classes will use the initialized data to create objects to be stored in each
 respective class. The `driver.cpp` file is used to execute the program.

The rental store uses the following classes:
- Store -  holds the functions to read data files and initialize the store, customers, and movies

- Customer - holds the functions to initialize each customer, and the action commands per customer
    - Borrow - denoted as "B", subtracts 1 from stock
    - Return - denoted as "R", adds 1 to stock
    - Inventory - prints complete store inventory 
    - History - prints customer transaction history
    
- CustomerDataBase - implements a hash table to record each customer by their ID number, name

- MovieInventory - implements a hash table to record each movie by movie information, movie

- StoreBuilder - initializes the Store object
    
- Movie - class that uses inheritance for each of its child classes for each movie genre
    - Comedy - denoted as "F"
    - Drama - denoted as "D"
    - Classic - denoted as "C"