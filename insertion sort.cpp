#include <iostream>
using namespace std;

// Swaps the values of two variables
void swap(int &a, int &b) {
    int temp = a; // Store the value of 'a' in a temporary variable to prevent losing the original value
    a = b; // Assign the value of 'b' to 'a' to complete the swap
    b = temp; // Assign the value of the temporary variable to 'b' to complete the swap
}

// Sorts an array using insertion sort algorithm
void insertionSort(int arrayToSort[], int sizeOfArray) {
    for (int i = 1; i < sizeOfArray; i++) {
        int j = i; // Set the starting value of 'j' to 'i' to define the range to iterate over
        while (j > 0) { // Iterate over the range until it's completely sorted
            if (arrayToSort[j] < arrayToSort[j - 1]) { // Check if the current element is smaller than the previous element
                swap(arrayToSort[j], arrayToSort[j - 1]); // Swap the two elements
            }
            j--; // Decrease the value of 'j' to continue iterating over the range
        }
    }
}


int main()
{
    int array[5] = {5, 4, 3, 2, 1};
    insertionSort(array, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << array[i];
    }
    return 0;
}