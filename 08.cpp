#include<iostream>
using namespace std;

//PART 1: Function Overloading
class SimplePrinter 
{
public:
    void showData(int i) {
        cout << "Printer knows this is a whole number: " << i << endl;
    }
    void showData(double d) {
        cout << "Printer knows this is a decimal number: " << d << endl;
    }
    void showData(const char* text) {
        cout << "Printer knows this is text: " << text << endl;
    }
    
    // The C++ compiler decides which 'showData' to use before the program runs
};

//Function Overriding (Run-Time Polymorphism)
//Base Class: The parent class for all shapes.
class BaseShape {
public:
    // The 'virtual' keyword is VITAL. It tells C++: 
    // "Wait until the program is running to decide which draw function to use."
    virtual void draw() 
    {
        cout << "Drawing a very generic shape." << endl;
    }
};

// Derived Class 1: It is a type of Shape.
class NiceCircle : public BaseShape {
public:
    // This 'draw' REPLACES the parent's 'draw' function.
    void draw() {
        cout << "Drawing a specific Circle!" << endl;
    }
};

// Derived Class 2: It is another type of Shape.
class CoolSquare : public BaseShape {
public:
    // This 'draw' also REPLACES the parent's 'draw' function.
    void draw() {
        cout << "Drawing a specific Square!" << endl;
    }
};

// A simple function that accepts any object that is a BaseShape type (using a pointer).
void runDraw(BaseShape* theShape) {
    // When this line runs, the computer checks what KIND of object 
    theShape->draw();
}

int main() {
    cout << "1. Overloading (Compile-Time Decision)" << endl;
    SimplePrinter p;
    p.showData(10); 
    p.showData(4.5);
    p.showData("Bye!");

    cout << "\n2. Overriding (Run-Time Decision)" << endl;

    // Instantiation
    NiceCircle myCircle;
    CoolSquare mySquare;
    cout << "Ask the function to draw a Circle:" << endl;
    runDraw(&myCircle); // The program correctly calls Circle's draw()

    cout << "Ask the function to draw a Square:" << endl;
    runDraw(&mySquare); // The program correctly calls Square's draw()
    
    return 0;
}
