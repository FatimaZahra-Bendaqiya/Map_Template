#include "Employee.h"													// Defines class Employee
#include "Book.h"
#include "Map.h"														// Defines template Map<Key, Value>
#include "KeyDoesNotExistException.h"														
#include <iostream>

using namespace std;

typedef unsigned int ID; 												// Identification number of employee
typedef Map<ID, Employee> Database; 									// Database of employees

typedef string Title;
typedef Map<Title, Book> BookDatabase;

void testEmployees();
void addEmployees(Database& database);
void modifyEmployees(Database& database);

void testBookDatabase();
void addBooks(BookDatabase& database);
void modifyBookDatabase(BookDatabase& database);

int main() {
	testEmployees();
	testBookDatabase();
}

void testEmployees(){
	Database database;
	addEmployees(database);
	cout << "Original database:\n" << endl << database << endl;

	Database newDatabase = database;									// Make a copy of database
	newDatabase.add(830505432, Employee("Ewa Nowak", "charwoman", 43));	// Add fourth employee
	modifyEmployees(newDatabase);

	cout << "Modified database:\n" << endl << newDatabase << endl;

	database = newDatabase;												// Update original database

	cout << "Database after the assignment:\n" << endl << database << endl;
}

void addEmployees(Database& database) {
	database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	// Add second employee
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	// Add third employee
	database.add(761028073, Employee("Fatima Bendaqiya", "CEO", 40)); // Adding data with the same key as the first employee
}

void modifyEmployees(Database& database) {
	Employee* employeePtr;

	employeePtr = database.find(510212881);								// Find employee using its ID
	employeePtr->position = "salesman";									// Modify the position of employee
	
	employeePtr = database.find(761028073);								// Find employee using its ID
	employeePtr->age = 29;												// Modify the age of employee
	try{
		employeePtr = database.find(761028777);
		employeePtr->age = 7;
	}
	catch(keyDoesNotExistException& noKey){
		cout << noKey.what() << endl;
	}
}

void testBookDatabase(){
	BookDatabase database;
	addBooks(database);
	cout << "Original database:\n" << endl << database << endl;

	BookDatabase newDatabase = database;
	newDatabase.add("A Little Life", Book("Hanya Yanagihara", "Novel", 737, borrowed));
	modifyBookDatabase(newDatabase);

	cout << "Modified database:\n" << endl << newDatabase << endl;

	database = newDatabase;

	cout << "Database after the assignment:\n" << endl << database << endl;
}

void addBooks(BookDatabase& database){
	database.add("Le Petit Prince", Book("Saint-Exupery Antoine", "Children's literature", 103, onTheBookShelf));
	database.add("Polish Doesn't Bite", Book("Collective study", "Coursebook", 152, onTheBookShelf));
	database.add("Coding For Dummies", Book("Abraham Nikhil", "Reference work", 288, borrowed));
}

void modifyBookDatabase(BookDatabase& database){
	Book* libPtr;

	libPtr = database.find("Coding For Dummies");
	libPtr->currentStatus = onTheBookShelf;

	libPtr = database.find("Polish Doesn't Bite");
	libPtr->currentStatus = borrowed;

	try{
		libPtr = database.find("Le Petit Prince");
		libPtr->currentStatus = borrowed;
	}
	catch(keyDoesNotExistException& noKey){
		cout << noKey.what() << endl;
	}
}
