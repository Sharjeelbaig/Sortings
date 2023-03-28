#include <iostream>
using namespace std;

// A helper function that finds the maximum value in an array
int findMax(int arr[], int n)
{
    int maxVal = arr[0]; // Initialize maxVal as the first element of the array
    for (int i = 1; i < n; i++) // Loop through the rest of the array
    {
        if (arr[i] > maxVal) // If the current element is greater than maxVal
        {
            maxVal = arr[i]; // Update maxVal with the current element
        }
    }
    return maxVal; // Return the maximum value in the array
}

// A helper function that counts the number of elements with each digit
void countDigits(int arr[], int n, int exp, int count[])
{
    for (int i = 0; i < n; i++) // Loop through the array
    {
        count[(arr[i] / exp) % 10]++; // Increment the count of the digit at the current place value
    }
}

// A helper function that updates the count array to include the counts from previous digits
void updateCount(int count[])
{
    for (int i = 1; i < 10; i++) // Loop through the count array starting from index 1
    {
        count[i] += count[i - 1]; // Add the count of the current digit to the count of the previous digit
    }
}

// A helper function that places each element in its correct position in the output array
void placeElement(int arr[], int n, int exp, int output[], int count[])
{
    for (int i = n - 1; i >= 0; i--) // Loop through the array in reverse order
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; // Place the current element in its correct position in the output array
        count[(arr[i] / exp) % 10]--; // Decrement the count of the digit at the current place value
    }
}

// The main radixSort function that calls the helper functions to sort the array
void radixSort(int arr[], int n)
{
    int maxVal = findMax(arr, n); // Find the maximum value in the array
    for (int exp = 1; maxVal / exp > 0; exp *= 10) // Loop through the digits, starting with the least significant digit
    {
        int output[n]; // Initialize an output array to store the sorted elements
        int count[10] = {0}; // Initialize a count array to keep track of the number of elements with each digit
        countDigits(arr, n, exp, count); // Count the number of elements with each digit at the current place value
        updateCount(count); // Update the count array to include the counts from previous digits
        placeElement(arr, n, exp, output, count); // Place each element in its correct position in the output array
        for (int i = 0; i < n; i++) // Copy the sorted elements back to the original array
        {
            arr[i] = output[i];
        }
    }
}



int main()
{
    int arr[8] = {1, 4, 8, 3, 5, 2,6,7};
     radixSort(arr, 8);
     for (int i = 0; i < 8; i++)
     {
         cout << arr[i];
     }
    
    return 0;
}