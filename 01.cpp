#include <iostream>
#include <string>

// This avoids having to write 'std::' before cout, string, etc.
using namespace std;

// Define the maximum size for our list
const int MAX_CAPACITY = 10;

class SimpleList {
private:
    // C-style array for storage (fixed size)
    string elements[MAX_CAPACITY];
    
    // Tracks the current number of items
    int current_size; 

public:
    // 1. Constructor: Defined inline.
    SimpleList() {
        // Initializes the size tracker to 0.
        current_size = 0;
        cout << "DEBUG: SimpleList object created." << endl;
    }

    // 2. Add Item: Defined inline.
    void addItem(const string& item) {
        if (current_size < MAX_CAPACITY) {
            elements[current_size] = item;
            current_size++;
        } else {
            cout << "Error: List is full! Cannot add " << item << "." << endl;
        }
    }

    // 3. Remove Item: Defined inline.
    void removeItem(const string& item) {
        int index_to_remove = -1;
        
        // Step 1: Find the item's index
        for (int i = 0; i < current_size; ++i) {
            if (elements[i] == item) {
                index_to_remove = i;
                break;
            }
        }

        if (index_to_remove != -1) {
            // Step 2: Shift subsequent elements left
            for (int i = index_to_remove; i < current_size - 1; ++i) {
                elements[i] = elements[i+1];
            }
            
            // Step 3: Decrement the size tracker
            current_size--;
            cout << "Successfully removed " << item << "." << endl;
        } else {
            cout << "Error: " << item << " not found in the list." << endl;
        }
    }

    // 4. Get Size: Defined inline.
    int getSize() const {
        return current_size;
    }

    // 5. Display List: Defined inline.
    void displayList() const {
        cout << "SimpleList contents (Size: " << current_size << "): [";
        for (int i = 0; i < current_size; ++i) {
            cout << elements[i];
            if (i < current_size - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};

// --- Simple Demonstration ---

int main() {
    SimpleList shoppingList;
    cout << "-----------------------------------" << endl;

    // Add items
    shoppingList.addItem("Milk");
    shoppingList.addItem("Bread");
    shoppingList.addItem("Eggs");
    cout << "Added Milk, Bread, Eggs." << endl;

    // Display and Get Size
    shoppingList.displayList(); 
    cout << "Current size is: " << shoppingList.getSize() << endl;
    cout << "-----------------------------------" << endl;

    // Remove an item
    shoppingList.removeItem("Bread");
    
    // Display again
    shoppingList.displayList();
    cout << "New size is: " << shoppingList.getSize() << endl;
    
    return 0;
}