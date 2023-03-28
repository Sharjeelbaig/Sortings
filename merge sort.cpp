#include <iostream>
using namespace std;


void merge(int arr[], int left[], int leftSize, int right[], int rightSize)
{
    int l = 0, r = 0, i = 0; // initialize counters

    while (l < leftSize && r < rightSize) { // loop through both arrays as long as they both have elements remaining
        if (left[l] < right[r]) { // if the left array element is smaller
            arr[i++] = left[l++]; // append it to the result array and move the left counter forward
        } else { // otherwise the right array element is smaller
            arr[i++] = right[r++]; // append it to the result array and move the right counter forward
        }
    }

    while (l < leftSize) { // if there are any elements remaining in the left array
        arr[i++] = left[l++]; // append them to the result array
    }

    while (r < rightSize) { // if there are any elements remaining in the right array
        arr[i++] = right[r++]; // append them to the result array
    }
}

void split(int arr[], int left[], int right[], int size)
{
    int mid = size / 2; // find the midpoint of the array

    for (int i = 0; i < mid; i++) { // loop through the first half of the array
        left[i] = arr[i]; // copy the elements into the left array
    }

    for (int i = mid; i < size; i++) { // loop through the second half of the array
        right[i - mid] = arr[i]; // copy the elements into the right array, adjusting the index to start at 0
    }
}

void mergeSort(int arr[], int size)
{
    if (size < 2) { // base case: if the array has 0 or 1 elements, it is already sorted
        return; // exit the function
    }

    int mid = size / 2; // find the midpoint of the array
    int left[mid], right[size - mid]; // create two sub-arrays to hold the left and right halves of the original array

    split(arr, left, right, size); // split the original array into its two halves

    mergeSort(left, mid); // recursively sort the left half
    mergeSort(right, size - mid); // recursively sort the right half

    merge(arr, left, mid, right, size - mid); // merge the sorted halves back into the original array
}



int main()
{
    int arr[] = {4, 7, 1, 9, 2, 8, 3, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    mergeSort(arr, size);

    cout << "\nAfter sorting: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
