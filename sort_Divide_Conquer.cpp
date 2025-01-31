#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <chrono>

using namespace std;
using namespace std::chrono;

int bruteForceComparisons = 0;
int divideAndConquerComparisons = 0;

void MinMax(int arr[], int size, int result[]) {
    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
        bruteForceComparisons += 2; // Two comparisons per iteration
    }
    result[0] = min;
    result[1] = max;
}

void DandQMinMax(int arr[], int low, int high, int &min, int &max) {
    if (low == high) {  // Single element
        min = max = arr[low];
        return;
    }

    if (high == low + 1) {  // Two elements
        divideAndConquerComparisons++;
        if (arr[low] < arr[high]) {
            min = arr[low];
            max = arr[high];
        } else {
            min = arr[high];
            max = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;
    int min1, max1, min2, max2;

    DandQMinMax(arr, low, mid, min1, max1);
    DandQMinMax(arr, mid + 1, high, min2, max2);

    divideAndConquerComparisons++;
    min = (min1 < min2) ? min1 : min2;

    divideAndConquerComparisons++;
    max = (max1 > max2) ? max1 : max2;
}

int main() {
    srand(time(0));

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    int *arr = new int[size];  // Dynamic memory allocation
    int result[2];

    // Generate random numbers in a reasonable range
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;  // Random numbers between 0 and 9999
    }

    // Brute Force Approach
    auto start1 = high_resolution_clock::now();
    MinMax(arr, size, result);
    auto end1 = high_resolution_clock::now();
    auto timeOfMinMax = duration_cast<microseconds>(end1 - start1);

    cout << "\nBrute Force Approach\n";
    cout << "Minimum Element: " << result[0] << endl;
    cout << "Maximum Element: " << result[1] << endl;
    cout << "Time taken: " << timeOfMinMax.count() << " microseconds" << endl;
    cout << "Comparisons: " << bruteForceComparisons << endl;

    // Divide and Conquer Approach
    int min, max;
    auto start2 = high_resolution_clock::now();
    DandQMinMax(arr, 0, size - 1, min, max);
    auto end2 = high_resolution_clock::now();
    auto timeOfDandQ = duration_cast<microseconds>(end2 - start2);

    cout << "\nDivide & Conquer Approach\n";
    cout << "Minimum Element: " << min << endl;
    cout << "Maximum Element: " << max << endl;
    cout << "Time taken: " << timeOfDandQ.count() << " microseconds" << endl;
    cout << "Comparisons: " << divideAndConquerComparisons << endl;

    delete[] arr; // Free dynamically allocated memory

    return 0;
}

