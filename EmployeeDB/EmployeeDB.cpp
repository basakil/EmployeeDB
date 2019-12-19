#include <iostream>
#include <stdexcept>
#include "EmployeeDB.h"

using namespace std;

namespace Records {

	Employee& EmployeeDB::addEmployee(const string& firstName,
		const string& lastName)
	{
		Employee theEmployee(firstName, lastName);
		theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
		theEmployee.hire();
		mEmployees.push_back(theEmployee);

		return mEmployees[mEmployees.size() - 1];
	}

	Employee& EmployeeDB::getEmployee(int employeeNumber)
	{
		for (auto& employee : mEmployees) {
			if (employee.getEmployeeNumber() == employeeNumber) {
				return employee;
			}
		}
		throw logic_error("No employee found.");
	}

	Employee& EmployeeDB::getEmployee(const string& firstName, const string& lastName)
	{
		for (auto& employee : mEmployees) {
			if (employee.getFirstName() == firstName &&
				employee.getLastName() == lastName) {
					return employee;
			}
		}
		throw logic_error("No employee found.");
	}

	void EmployeeDB::displayAll() const
	{
		cout << "Id\tName\tSurname\tIsHired\tSalary\n";
		write(cout);
		//for (const auto& employee : mEmployees) {
		//	employee.write(cout);
		//}
	}

	void EmployeeDB::displayCurrent() const
	{
		for (const auto& employee : mEmployees) {
			if (employee.isHired())
				employee.display();
		}
	}

	void EmployeeDB::displayFormer() const
	{
		for (const auto& employee : mEmployees) {
			if (!employee.isHired())
				employee.display();
		}
	}

	int EmployeeDB::read(std::istream& is) {
		int count = 0;
		string str;
		
		for (; is ;) {
			Employee employee("","");
			employee.read(is);
			//@TODO: there may exist an employee with the same id..
			mEmployees.push_back(employee);
			++count;
			if (!is || is.get() == std::char_traits<char>::eof()) {
				break;
			}
		}

		return count;
	}

	int EmployeeDB::write(std::ostream& os) const {
		int count = 0;
		int size = mEmployees.size();
		for (const Employee& employee : mEmployees) {
			employee.write(os);
			++count;
			if (count < size) {
				os << '\n';
			}
		}
		return count;
	}

}
