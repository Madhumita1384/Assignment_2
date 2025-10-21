#include <iostream>
#include <string>

using namespace std;

// --- 1. Base Class (Level 1) ---
class Person {
protected:
    string name;
    int age;

public:
    // Constructor
    Person(const string& n, int a) {
        name = n;
        age = a;
        cout << "DEBUG: Person object created." << endl;
    }
    
    void displayPersonInfo() const {
        cout << "Name: " << name << ", Age: " << age;
    }
};

// --- 2. Intermediate Derived Class (Level 2) ---
// Employee inherits from Person
class Employee : public Person {
protected:
    int employeeID;
    double salary;

public:
    // Constructor: Must call the immediate base class (Person) constructor
    Employee(const string& n, int a, int id, double s) 
        : Person(n, a) {
        employeeID = id;
        salary = s;
        cout << "DEBUG: Employee object created." << endl;
    }

    void displayEmployeeInfo() const {
        // Accesses inherited 'name' and 'age'
        displayPersonInfo(); 
        cout << ", ID: " << employeeID << ", Salary: $" << salary;
    }

    void calculateBonus() const {
        cout << name << " gets a base bonus of $" << salary * 0.10 << "." << endl;
    }
};

// --- 3. Final Derived Class (Level 3) ---
// Manager inherits from Employee
class Manager : public Employee {
private:
    int teamSize;

public:
    // Constructor: Must call the immediate base class (Employee) constructor, 
    // which in turn calls the Person constructor.
    Manager(const string& n, int a, int id, double s, int ts)
        : Employee(n, a, id, s) {
        teamSize = ts;
        cout << "DEBUG: Manager object created." << endl;
    }

    void displayManagerInfo() const {
        // Inherits and displays all info from Employee (which includes Person info)
        displayEmployeeInfo();
        cout << ", Team Size: " << teamSize << "." << endl;
    }

    // Overrides the Employee's bonus calculation for a higher rate
    void calculateBonus() const {
        // Accesses inherited 'salary'
        cout << name << " gets a manager bonus of $" << salary * 0.25 << "." << endl;
    }
};

// --- Demonstration ---

int main() {
    // Creating a Manager object
    // Constructors are called in order: Person -> Employee -> Manager
    Manager boss("Alice Johnson", 45, 1001, 80000.0, 12);
    cout << "---------------------------------------" << endl;
    
    // Demonstrate data and functions passing through the chain
    boss.displayManagerInfo(); // Uses data from all three levels
    
    cout << "---------------------------------------" << endl;
    
    boss.calculateBonus(); // Calls the Manager's overridden function

    return 0;
}