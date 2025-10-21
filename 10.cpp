#include<iostream>
using namespace std;
class BaseShape {
public:
    // A virtual destructor is good practice for base classes.
    virtual ~BaseShape() {} 
    
    // This is a PURE VIRTUAL function. "= 0" means every child class MUST implement this.
    virtual double findArea() = 0; 
};

// Circle is a child (derived) class of BaseShape.
class Circle : public BaseShape {
private:
    double radius;
    // Using a simpler PI value for beginners.
    const double PI = 3.14; 

public:
    // Constructor sets the radius.
    Circle(double r) {
        radius = r;
    }

    // We MUST implement findArea() because BaseShape said so.
    double findArea() override {
        return PI * radius * radius; // Formula for Circle Area
    }
};


// Square is another child (derived) class of BaseShape.
class Square : public BaseShape {
private:
    double sideLength;

public:
    Square(double s) {
        sideLength = s;
    }
    // We MUST implement findArea() for the Square.
    double findArea() override {
        return sideLength * sideLength; // Formula for Square Area
    }
};

void calculateArea(BaseShape* shapePtr) {
    // This calls the correct area function (Circle's or Square's) 
    // when the program is running (Run-Time Polymorphism).
    cout << "The calculated area is: " << shapePtr->findArea() << endl;
}

int main() {
    cout << "--- Abstract Class Demonstration ---" << endl;

    // We CANNOT do this: BaseShape genericShape; 

    Circle myCircle(5.0); 
    Square mySquare(8.0); 
 
    cout << "Circle (radius 5) area:" << endl;
    calculateArea(&myCircle); 

    cout << "\nSquare (side 8) area:" << endl;
    calculateArea(&mySquare); 

    return 0;
}
