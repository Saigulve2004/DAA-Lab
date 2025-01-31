#include <iostream>
#include <cstdlib>   // for rand()
#include <ctime>     // for time()
#include <algorithm> // for sort()
#include <chrono>    // for high-resolution timing
#include <sstream>   // for stringstream

using namespace std;
using namespace std::chrono;

// Linear Search function
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // element found, return index
        }
    }
    return -1; // element not found
}

// Non-recursive Binary Search function
int binarySearchNonRecursive(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // element found, return index
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // element not found
}

// Recursive Binary Search function
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // element found, return index
        }

        if (arr[mid] < target) {
            return binarySearchRecursive(arr, mid + 1, right, target);
        } else {
            return binarySearchRecursive(arr, left, mid - 1, target);
        }
    }
    return -1; // element not found
}

int main() {
   

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Create and fill the array with random numbers
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // random number between 0 and 99
    }

    // Print the array
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform Linear Search
    int target;
    cout << "Enter the target number to search: ";
    cin >> target;

    // Measure time for Linear Search
    auto startLinear = high_resolution_clock::now();
    int linearIndex = linearSearch(arr, size, target);
    auto endLinear = high_resolution_clock::now();

    // Sort the array for binary search
    sort(arr, arr + size);

    // Print the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Measure time for Non-recursive Binary Search
    auto startNonRecursive = high_resolution_clock::now();
    int binaryIndexNonRecursive = binarySearchNonRecursive(arr, size, target);
    auto endNonRecursive = high_resolution_clock::now();

    // Measure time for Recursive Binary Search
    auto startRecursive = high_resolution_clock::now();
    int binaryIndexRecursive = binarySearchRecursive(arr, 0, size - 1, target);
    auto endRecursive = high_resolution_clock::now();

    // Calculate durations in milliseconds
    auto timeLinear = duration_cast<nanoseconds>(endLinear - startLinear).count();
    auto timeNonRecursive = duration_cast<nanoseconds>(endNonRecursive - startNonRecursive).count();
    auto timeRecursive = duration_cast<nanoseconds>(endRecursive - startRecursive).count();

    // Display results and time taken
    cout << "\nResults:" << endl;
    if (linearIndex != -1) {
        stringstream ss;
        ss << "Found at index " << linearIndex;
        cout << "Linear Search: " << ss.str() << " (Time: " << timeLinear << " ms)" << endl;
    } else {
        cout << "Linear Search: Not Found (Time: " << timeLinear << " ms)" << endl;
    }

    if (binaryIndexNonRecursive != -1) {
        stringstream ss;
        ss << "Found at index " << binaryIndexNonRecursive;
        cout << "Non-recursive Binary Search: " << ss.str() << " (Time: " << timeNonRecursive << " ms)" << endl;
    } else {
        cout << "Non-recursive Binary Search: Not Found (Time: " << timeNonRecursive << " ms)" << endl;
    }

    if (binaryIndexRecursive != -1) {
        stringstream ss;
        ss << "Found at index " << binaryIndexRecursive;
        cout << "Recursive Binary Search: " << ss.str() << " (Time: " << timeRecursive << " ms)" << endl;
    } else {
        cout << "Recursive Binary Search: Not Found (Time: " << timeRecursive << " ms)" << endl;
    }

    // Comparison
    cout << "\nComparison of Time Taken:" << endl;
    cout << "Linear Search: " << timeLinear << " ms" << endl;
    cout << "Non-recursive Binary Search: " << timeNonRecursive << " ms" << endl;
    cout << "Recursive Binary Search: " << timeRecursive << " ms" << endl;

    return 0;
}
