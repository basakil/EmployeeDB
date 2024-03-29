#include <iostream>
#include "Employee.h"

using namespace std;

namespace Records {

	Employee::Employee(const Employee& other)
	{
		cout << "Employee copy constructor called for id=" << other.mEmployeeNumber << endl;

		mEmployeeNumber = other.mEmployeeNumber;
		mFirstName = other.mFirstName;
		mLastName = other.mLastName;
		mHired = other.mHired;
		mSalary = other.mSalary;

	}

	Employee::Employee(Employee&& other)
	{
		cout << "Employee move constructor called for id=" << other.mEmployeeNumber << endl;

		mEmployeeNumber = other.mEmployeeNumber;
		mFirstName = other.mFirstName;
		mLastName = other.mLastName;
		mHired = other.mHired;
		mSalary = other.mSalary;

		other.mEmployeeNumber = -101;
	}

	Employee::Employee(const std::string& firstName, const std::string& lastName)
		: mFirstName(firstName)
		, mLastName(lastName)
	{
	}

	void Employee::promote(int raiseAmount)
	{
		setSalary(getSalary() + raiseAmount);
	}

	void Employee::demote(int demeritAmount)
	{
		setSalary(getSalary() - demeritAmount);
	}

	void Employee::hire()
	{
		mHired = true;
	}

	void Employee::fire()
	{
		mHired = false;
	}

	void Employee::display() const
	{
		cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
		cout << "-------------------------" << endl;
		cout << (isHired() ? "Current Employee" : "Former Employee") << endl;
		cout << "Employee Number: " << getEmployeeNumber() << endl;
		cout << "Salary: $" << getSalary() << endl;
		cout << endl;
	}

	// Getters and setters
	void Employee::setFirstName(const string& firstName)
	{
		mFirstName = firstName;
	}

	const string& Employee::getFirstName() const
	{
		return mFirstName;
	}

	void Employee::setLastName(const string& lastName)
	{
		mLastName = lastName;
	}

	const string& Employee::getLastName() const
	{
		return mLastName;
	}

	void Employee::setEmployeeNumber(int employeeNumber)
	{
		mEmployeeNumber = employeeNumber;
	}

	int Employee::getEmployeeNumber() const
	{
		return mEmployeeNumber;
	}

	void Employee::setSalary(int salary)
	{
		mSalary = salary;
	}

	int Employee::getSalary() const
	{
		return mSalary;
	}

	bool Employee::isHired() const
	{
		return mHired;
	}

	void Employee::read(istream& is)
	{
		is >> mEmployeeNumber >> mFirstName >> mLastName >> mHired >> mSalary;
	}


	void Employee::write(ostream& os) const
	{
		os << mEmployeeNumber << '\t' << mFirstName << '\t' << mLastName << '\t' << mHired << '\t' << mSalary;
	}

	ostream& operator<<(ostream& os, const Employee& emp)
	{
		emp.write(os);
		return os;
	}

	istream& operator>>(istream& is, Employee& emp)
	{
		emp.read(is);
		return is;
	}

}
