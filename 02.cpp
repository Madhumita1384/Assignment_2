#include <iostream>
#include <string> // We still need 'string' for key/value types, even if we only include iostream.

// This avoids writing 'std::' before cout, endl, and string.
using namespace std;

// Define the maximum size for our map
const int MAX_CAPACITY = 5; 

class SimpleDictionary {
private:
    // Parallel C-style arrays for keys and values
    string keys[MAX_CAPACITY];
    string values[MAX_CAPACITY];
    
    // Tracks the current number of pairs
    int current_size; 

public:
    // 1. Constructor
    SimpleDictionary() {
        // Initializes the size tracker to 0.
        current_size = 0;
        cout << "DEBUG: Dictionary structure initialized." << endl;
    }

    // --- Core Methods ---

    // Find Index (Helper function: returns index if found, -1 otherwise)
    int findIndex(const string& key) const {
        for (int i = 0; i < current_size; ++i) {
            if (keys[i] == key) {
                return i; // Key found at index i
            }
        }
        return -1; // Key not found
    }

    // 2. Add or Update Pair
    void addPair(const string& key, const string& value) {
        int index = findIndex(key);

        if (index != -1) {
            // Key found: Update existing value
            values[index] = value;
            cout << "Key '" << key << "' updated to: " << value << endl;
        } else if (current_size < MAX_CAPACITY) {
            // Key not found AND space is available: Add new pair
            keys[current_size] = key;
            values[current_size] = value;
            current_size++;
            cout << "Key-value pair added: " << key << ": " << value << endl;
        } else {
            // No space available
            cout << "Error: Dictionary is full! Cannot add " << key << "." << endl;
        }
    }

    // 3. Search for a Key (Get Value)
    string searchKey(const string& key) const {
        int index = findIndex(key);
        
        if (index != -1) {
            return values[index]; // Return the corresponding value
        } else {
            return "Key Not Found";
        }
    }

    // 4. Display All Pairs
    void displayAll() const {
        if (current_size == 0) {
            cout << "The dictionary is empty." << endl;
            return;
        }

        cout << "\n--- Dictionary Contents (" << current_size << " pairs) ---" << endl;
        for (int i = 0; i < current_size; ++i) {
            cout << keys[i] << ": " << values[i] << endl;
        }
        cout << "-----------------------------------" << endl;
    }
};

// --- Simple Demonstration ---

int main() {
    SimpleDictionary userRoles;
    cout << "-----------------------------------" << endl;

    // 1. Add pairs
    userRoles.addPair("Bob", "Admin");
    userRoles.addPair("Alice", "User");
    userRoles.addPair("Charlie", "Guest");

    cout << "\n-----------------------------------" << endl;
    // 2. Search for a key
    cout << "Bob's role is: " << userRoles.searchKey("Bob") << endl;
    cout << "Frank's role is: " << userRoles.searchKey("Frank") << endl;
    
    // 3. Update a value
    userRoles.addPair("Bob", "SuperAdmin"); 

    // 4. Display all pairs
    userRoles.displayAll();

    return 0;
}