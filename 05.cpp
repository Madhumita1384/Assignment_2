#include <iostream>
#include <string>

using namespace std;

// --- 1. Base Class A ---
class Person {
protected:
    string name;

public:
    Person(const string& n) : name(n) {
        cout << "DEBUG: Person object created." << endl;
    }
    
    // Function that exists in both base classes (creates ambiguity)
    void displayInfo() const {
        cout << "Role: Basic Person." << endl;
    }
};

// --- 2. Base Class B ---
class Athlete {
protected:
    string sport;

public:
    Athlete(const string& s) : sport(s) {
        cout << "DEBUG: Athlete object created." << endl;
    }

    // Function that exists in both base classes (creates ambiguity)
    void displayInfo() const {
        cout << "Role: Competitive Athlete." << endl;
    }
};

// --- 3. Derived Class (Multiple Inheritance) ---
// SportsPerson publicly inherits from BOTH Person and Athlete
class SportsPerson : public Person, public Athlete {
private:
    int careerYears;

public:
    // Constructor: Must call BOTH base class constructors
    SportsPerson(const string& n, const string& s, int years)
        : Person(n), Athlete(s), careerYears(years) {
        cout << "DEBUG: SportsPerson object created." << endl;
    }

    // Method to display all information
    void displayAllInfo() const {
        cout << "\n--- SportsPerson Report ---" << endl;
        cout << "Name: " << name << endl; // Inherited from Person
        cout << "Sport: " << sport << endl; // Inherited from Athlete
        cout << "Career Length: " << careerYears << " years." << endl;
        
        // **Ambiguity Resolution using Scope Resolution**
        cout << "Person Role: ";
        Person::displayInfo(); // Explicitly calls Person's version
        
        cout << "Athlete Role: ";
        Athlete::displayInfo(); // Explicitly calls Athlete's version
        cout << "---------------------------\n";
    }

    // A final function specific to this class
    void shoutVictory() const {
        cout << name << " shouts: VICTORY for " << sport << "!" << endl;
    }
};

// --- Demonstration ---

int main() {
    // Create a SportsPerson object
    SportsPerson lebron("LeBron James", "Basketball", 20);
    
    // Demonstrate resolution and functionality
    lebron.displayAllInfo();
    lebron.shoutVictory();

    // ERROR Example: The following line would cause a compiler error due to ambiguity:
    // lebron.displayInfo(); 

    return 0;
}