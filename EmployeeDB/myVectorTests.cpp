#include "myVector.h"
#include <iostream>
#include "Employee.h"

using namespace std;
using namespace Records;

int main__myVector() {

	myVector1<int> vec;

	vec.push_back(3);
	vec.push_back(5);

	vec.at(1) = 7;
	cout << "vec[1] = " << vec.at(1) << endl;

	//myVector1<Employee> employees;

	//Employee employee1("emp1", "sn_emp1");
	//employees.push_back(employee1);

	//cout << "employee[0] = " << employees.at(0).getEmployeeNumber() << endl;

	return 0;
}