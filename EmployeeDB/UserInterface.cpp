#include <iostream>
#include <stdexcept>
#include <exception>
#include <fstream>

#include "EmployeeDB.h"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(EmployeeDB& db);
void doFire(EmployeeDB& db);
void doPromote(EmployeeDB& db);
void doDemote(EmployeeDB& db);
void readFromFile(EmployeeDB& db);
void writeToFile(EmployeeDB& db);

int main()
{
	EmployeeDB employeeDB;

	bool done = false;
	while (!done) {
		int selection = displayMenu();
		switch (selection) {
		case 0:
			done = true;
			break;
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			employeeDB.displayAll();
			break;
		case 5:
			employeeDB.displayCurrent();
			break;
		case 6:
			employeeDB.displayFormer();
			break;
        case 7:
            readFromFile(employeeDB);
            break;
        case 8:
            writeToFile(employeeDB);
            break;
		default:
			cerr << "Unknown command." << endl;
			break;
		}
	}

	return 0;
}

int displayMenu()
{
	// Note: no input check is performed....

    int selection;

    cout << endl;
    cout << "Employee EmployeeDB" << endl;
    cout << "-----------------" << endl;
    cout << "1) Hire a new employee" << endl;
    cout << "2) Fire an employee" << endl;
    cout << "3) Promote an employee" << endl;
    cout << "4) List all employees" << endl;
    cout << "5) List all current employees" << endl;
    cout << "6) List all former employees" << endl;
    cout << "7) Read from file" << endl;
    cout << "8) Write to file" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "---> ";
    
	cin >> selection;
    
	return selection;
}

void readFromFile(EmployeeDB& db) {
    string filename;

    cout << "Filename: ";
    cin >> filename;

    ifstream file(filename);
    if (file.fail()) {
        cout << "fileopen failed: " << filename << endl;
        return;
    }

    cout << "read " << db.read(file) << " employees..." << endl;
}

void writeToFile(EmployeeDB& db) {
    string filename;

    cout << "Filename: ";
    cin >> filename;

    ofstream file(filename, ios_base::trunc);
    if (file.fail()) {
        cout << "fileopen failed: " << filename << endl;
        return;
    }

    cout << "wrote " << db.write(file) << " employees..." << endl;
}

void doHire(EmployeeDB& db)
{
    string firstName;
    string lastName;

    cout << "First name? ";
    cin >> firstName;
    cout << "Last name? ";
    cin >> lastName;
    
    Employee & emp = db.addEmployee(firstName, lastName);
}

void doFire(EmployeeDB& db)
{
    int employeeNumber;

    cout << "Employee number? ";
    cin >> employeeNumber;

    try {
        Employee& emp = db.getEmployee(employeeNumber);
        emp.fire();
        cout << "Employee " << employeeNumber << " terminated." << endl;
    } catch (const std::logic_error& exception) {
        cerr << "Unable to terminate employee: " << exception.what() << endl;
    }
}

void doPromote(EmployeeDB& db)
{
    int employeeNumber;
    int raiseAmount;

    cout << "Employee number? ";
    cin >> employeeNumber;
    cout << "How much of a raise? ";
    cin >> raiseAmount;

    try {
        Employee& emp = db.getEmployee(employeeNumber);
        emp.promote(raiseAmount);
    } catch (const std::logic_error& exception) {
        cerr << "Unable to promote employee: " << exception.what() << endl;
    }
}
