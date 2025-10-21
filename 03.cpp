#include <iostream>

using namespace std;

// --- 1. Base Class Declaration ---
class Shape {
protected:
    // Protected variables can be accessed by the derived class (Rectangle)
    double width;
    double height;

public:
    // Constructor for Shape
    Shape(double w, double h) {
        width = w;
        height = h;
        cout << "Shape created with dimensions: " << width << " x " << height << endl;
    }
    
    // Virtual destructor is important for proper cleanup in inheritance, 
    // but for simplicity, we keep it basic here.
    ~Shape() {
        // Simple destructor message
    }

    // Common method for all shapes (even if it's not implemented yet in the base class)
    void printDimensions() const {
        cout << "Dimensions: " << width << " units by " << height << " units." << endl;
    }
    
    // A placeholder method for the area, which all shapes must have
    double getArea() const {
        // Returns 0 in the base class, as a generic shape doesn't have a specific formula
        return 0.0; 
    }
    
    // A placeholder method for the perimeter
    double getPerimeter() const {
        return 0.0; 
    }
};

// --- 2. Derived Class Declaration ---
// Rectangle publicly inherits from Shape
class Rectangle : public Shape {
public:
    // Constructor for Rectangle
    // It must call the base class constructor (Shape) using the initialization list
    Rectangle(double w, double h) : Shape(w, h) {
        cout << "Rectangle object created." << endl;
    }

    // Override the getArea method with the specific rectangle formula
    double getArea() const {
        // Accesses 'width' and 'height' which were inherited from Shape (protected access)
        return width * height;
    }

    // Override the getPerimeter method with the specific rectangle formula
    double getPerimeter() const {
        // Accesses inherited 'width' and 'height'
        return 2 * (width + height);
    }
};

// --- Demonstration ---

int main() {
    // Create a Rectangle object. It first calls the Shape constructor, then the Rectangle constructor.
    Rectangle rect(10.0, 5.0);
    cout << "---------------------------------------" << endl;
    
    // Accessing an inherited method (from Shape)
    rect.printDimensions();
    
    // Accessing the overridden methods (specific to Rectangle)
    cout << "Area of the rectangle: " << rect.getArea() << " sq units." << endl;
    cout << "Perimeter of the rectangle: " << rect.getPerimeter() << " units." << endl;
    
    return 0;
}