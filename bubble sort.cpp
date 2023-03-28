#include <iostream>
using namespace std;

// Swaps the values of two integers
void swapValues(int &a, int &b) {
    int temp = a; // Store the value of 'a' in a temporary variable so that we don't lose it during the swap
    a = b; // Assign the value of 'b' to 'a', effectively swapping the values of 'a' and 'b'
    b = temp; // Assign the value of the temporary variable (which holds the original value of 'a') to 'b', completing the swap
}

// Returns the index of the minimum value in the given range of the array
int findMinIndex(int arr[], int start, int end) {
    int minIndex = start; // Assume that the minimum value is at the start of the range
    for (int i = start + 1; i <= end; i++) { // Loop through the remaining elements in the range
        if (arr[i] < arr[minIndex]) { // If we find an element that is smaller than the current minimum value,
            minIndex = i; // update the index of the minimum value to the index of the new minimum value
        }
    }
    return minIndex; // Return the index of the minimum value
}

// Moves the smallest value in the given range to the start of the range
void bubbleUp(int arr[], int start, int end) {
    int minIndex = findMinIndex(arr, start, end); // Find the index of the minimum value in the range
    if (minIndex != start) { // If the minimum value is not already at the start of the range (i.e., if it is at a later index in the range),
        swapValues(arr[start], arr[minIndex]); // swap it with the element at the start of the range
    }
}

// Sorts the given array using bubble sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) { // Loop through all elements except the last one
        bubbleUp(arr, i, size - 1); // Move the smallest value in the remaining range to the start of the range
    }
}



int main()
{
    int array[5] = {5, 4, 3, 2, 1};
    bubbleSort(array, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << array[i];
    }
    return 0;
}