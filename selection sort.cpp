#include <iostream>
using namespace std;

// Swaps the values of two integers
void swap(int &a, int &b)
{
    int temp = a; // Store the value of 'a' in a temporary variable so that we don't lose it during the swap
    a = b;        // Assign the value of 'b' to 'a', effectively swapping the values of 'a' and 'b'
    b = temp;     // Assign the value of the temporary variable (which holds the original value of 'a') to 'b', completing the swap
}

// Finds the index of the minimum value in a sub-array
int findMinIndex(int arr[], int startIndex, int endIndex)
{
    int minIndex = startIndex;                       // Assume that the minimum value is at the start of the sub-array
    for (int i = startIndex + 1; i <= endIndex; i++) // Loop through the remaining elements in the sub-array
    {
        if (arr[i] < arr[minIndex]) // If we find an element that is smaller than the current minimum value,
        {
            minIndex = i; // update the index of the minimum value to the index of the new minimum value
        }
    }
    return minIndex; // Return the index of the minimum value
}

// Sorts the given array in ascending order using selection sort
void selectionSort(int arrayToSort[], int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray - 1; i++) // Loop through the array from the first element to the second-last element
    {
        int minIndex = findMinIndex(arrayToSort, i, sizeOfArray - 1); // Find the index of the minimum value in the unsorted portion of the array
        swap(arrayToSort[i], arrayToSort[minIndex]);                  // Swap the smallest element with the current element
    }
}

int main()
{
    int array[5] = {5, 4, 3, 2, 1};
    selectionSort(array, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << array[i];
    }
    return 0;
}