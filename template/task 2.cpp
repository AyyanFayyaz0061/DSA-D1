#include <iostream>
using namespace std;

class Employee {
public:
    virtual double calculateSalary() = 0;
    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
private:
    double salary;

public:
    FullTimeEmployee(double s) {
        salary = s;
    }

    double calculateSalary() {
        return salary;
    }
};

class PartTimeEmployee : public Employee {
private:
    int hours;
    double rate;

public:
    PartTimeEmployee(int h, double r) {
        hours = h;
        rate = r;
    }

    double calculateSalary() {
        return hours * rate;
    }
};

int main() {
    FullTimeEmployee e1(50000);
    PartTimeEmployee e2(40, 500);

    cout << "Full Time Employee Salary: "
        << e1.calculateSalary() << endl;

    cout << "Part Time Employee Salary: "
        << e2.calculateSalary() << endl;

    return 0;
}