#include<iostream>
using namespace std;
// We set a maximum limit for how many numbers the array can hold.
const int MAX_COUNT = 10; 
// The main class that holds our numbers and the sorting tools.
class SimpleArraySorter {
private:
    // This is the actual list (array) where we keep the numbers.
    int theNumbers[MAX_COUNT];
    
    // This tracks how many numbers the user has actually put in.
    int count;

    // A small helper function to swap two numbers. It is private so only the class can use it.
    void switchPlaces(int& num1, int& num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

public:
    
    // The Constructor: This runs when the object is first created.
    SimpleArraySorter() {
        // Start the count at zero, meaning the array is empty.
        count = 0;
    }

    // Method to put a new number into the array.
    void addNumber(int value) {
        // Check if there is still space left.
        if (count < MAX_COUNT) {
            theNumbers[count] = value;
            count = count + 1; // Increase the count after adding.
        } else {
            // Show an error message if the array is full.
            cerr << "ERROR: The list is full. Cannot add " << value << endl;
        }
    }

    // Method to print all the numbers in the array.
    void printNumbers() {
        cout << "List: [";
        // Loop through all the numbers we have added.
        for (int i = 0; i < count; ++i) {
            cout << theNumbers[i];
            // Add a comma after every number except the last one.
            if (i < count - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    // 1. Bubble Sort: Pushes the largest numbers to the end like bubbles rising.
    void doBubbleSort() {
        if (count < 2) return; // Nothing to do if 0 or 1 number.

        // Outer loop: Goes through the list many times.
        for (int i = 0; i < count - 1; ++i) {
            bool didSwap = false;
            // Inner loop: Compares adjacent numbers.
            for (int j = 0; j < count - i - 1; ++j) {
                // If the number on the left is bigger than the one on the right, switch them.
                if (theNumbers[j] > theNumbers[j + 1]) {
                    switchPlaces(theNumbers[j], theNumbers[j + 1]);
                    didSwap = true;
                }
            }
            // If we didn't switch anything in a full pass, the list is sorted!
            if (didSwap == false) {
                break;
            }
        }
    }

    // 2. Insertion Sort: Takes one number at a time and puts it in the correct place in the already sorted part of the list.
    void doInsertionSort() {
        if (count < 2) return;

        // Loop starting from the second number (index 1).
        for (int i = 1; i < count; ++i) {
            int currentNumber = theNumbers[i]; 
            int j = i - 1; 

            // Keep moving numbers in the sorted part (to the left) to the right 
            // until we find the spot for the currentNumber.
            while (j >= 0 && theNumbers[j] > currentNumber) {
                theNumbers[j + 1] = theNumbers[j];
                j = j - 1;
            }
            // Put the currentNumber into its correct empty spot.
            theNumbers[j + 1] = currentNumber;
        }
    }

    // 3. Selection Sort: Finds the smallest number and moves it to the beginning of the unsorted part.
    void doSelectionSort() {
        if (count < 2) return;

        // Outer loop: Marks the beginning of the unsorted part.
        for (int i = 0; i < count - 1; ++i) {
            int minIndex = i;
            
            // Inner loop: Look for the smallest number from index i to the end.
            for (int j = i + 1; j < count; ++j) {
                if (theNumbers[j] < theNumbers[minIndex]) {
                    minIndex = j; // Found a new smallest number index.
                }
            }

            // Swap the smallest number found (at minIndex) with the current number at index i.
            if (minIndex != i) {
                switchPlaces(theNumbers[minIndex], theNumbers[i]);
            }
        }
    }
};
int main() {

    SimpleArraySorter mySorter;
    int dataSet[] = {55, 10, 80, 20, 44, 99};
    int dataCount = 6; 
    for(int i = 0; i < dataCount; ++i) {
        mySorter.addNumber(dataSet[i]);
    }

    cout << "Original List: ";
    mySorter.printNumbers(); 

    cout << "\n--- We will sort with Bubble Sort ---" << endl;
    mySorter.doBubbleSort();
    cout << "Sorted Result: ";
    mySorter.printNumbers();
    return 0;
}
