#include <iostream>
#include <string>

using namespace std;

// Forward declaration of the Sports class is necessary 
// because Student refers to it in the friend function prototype.
class Sports;

// --- 1. Class Student ---
class Student {
private:
    string name;
    int academicMarks;

public:
    // Constructor
    Student(const string& n, int marks) {
        name = n;
        academicMarks = marks;
    }
    
    // Declaration of a FRIEND function
    // This grants the comparePerformance function special access
    // to the private and protected members of the Student class.
    friend void comparePerformance(const Student& stu, const Sports& spt);

    // Public method to display info
    void displayStudentInfo() const {
        cout << "Student: " << name << ", Academic Marks: " << academicMarks << endl;
    }
};

// --- 2. Class Sports ---
class Sports {
private:
    string sportName;
    int score; // E.g., points scored, seconds taken, etc.

public:
    // Constructor
    Sports(const string& sport, int s) {
        sportName = sport;
        score = s;
    }

    // Since 'comparePerformance' is a stand-alone, non-member function, 
    // it must also be declared as a friend inside the Sports class 
    // to access its private members.
    friend void comparePerformance(const Student& stu, const Sports& spt);

    // Public method to display info
    void displaySportsInfo() const {
        cout << "Sport: " << sportName << ", Competition Score: " << score << endl;
    }
};


// --- 3. Friend Function Definition ---
// This function is NOT a member of either class. It is a stand-alone function.
void comparePerformance(const Student& stu, const Sports& spt) {
    cout << "\n--- Performance Comparison ---" << endl;
    
    // Accessing private members using the dot operator on the object reference:
    // This is only possible because comparePerformance is a friend of BOTH classes.
    cout << "Comparing " << stu.name << "'s marks vs. " << spt.sportName << " score." << endl;
    
    if (stu.academicMarks > spt.score) {
        cout << stu.name << " achieved a higher numerical score in academics (" << stu.academicMarks << ")." << endl;
    } else if (spt.score > stu.academicMarks) {
        cout << stu.name << " achieved a higher numerical score in sports (" << spt.score << ")." << endl;
    } else {
        cout << "Academic and sports scores are equal (" << stu.academicMarks << ")." << endl;
    }
    cout << "----------------------------" << endl;
}


// --- Demonstration ---
int main() {
    // Create objects of the two unrelated classes
    Student alice("Alice", 95);
    Sports basketball("Basketball", 100);

    alice.displayStudentInfo();
    basketball.displaySportsInfo();

    // Call the friend function to access and compare their private data
    comparePerformance(alice, basketball);
    
    // Second Example
    Student bob("Bob", 88);
    Sports running("100m Dash", 88);
    
    bob.displayStudentInfo();
    running.displaySportsInfo();
    
    comparePerformance(bob, running);

    return 0;
}