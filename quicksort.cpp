#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Function to find the k-th smallest element using the Median of Medians algorithm
int medianOfMedians(vector<int>& arr, int n, int k) {
    if (n <= 5) {
        sort(arr.begin(), arr.begin() + n);
        return arr[k];
    }

    vector<int> medians;

    for (int i = 0; i < n / 5; i++) {
        medians.push_back(medianOfMedians(arr, 5, 2)); // Get median of each group
    }
    if (n % 5 != 0) {
        medians.push_back(medianOfMedians(arr, n % 5, (n % 5) / 2));
    }

    return medianOfMedians(medians, medians.size(), medians.size() / 2);
}

// Quick Sort function
void quickSort(vector<int>& arr, int n) {
    if (n <= 1) return;

    int pivot = medianOfMedians(arr, n, n / 2);
    vector<int> low, high;

    for (int i = 0; i < n; i++) {
        if (arr[i] < pivot) {
            low.push_back(arr[i]);
        } else if (arr[i] > pivot) {
            high.push_back(arr[i]);
        }
    }

    quickSort(low, low.size());
    quickSort(high, high.size());

    // Combine the results back into arr
    int index = 0;
    for (int val : low) {
        arr[index++] = val;
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == pivot) {
            arr[index++] = pivot;
        }
    }
    for (int val : high) {
        arr[index++] = val;
    }
}

// Function to measure time taken to sort a large list
void measureTime(int n) {
    vector<int> arr(n);
    srand(static_cast<unsigned int>(time(0)));

    // Fill the array with random integers
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 10000; // Random integers between 0 and 9999
    }

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, n);
    auto end = chrono::high_resolution_clock::now();

    // Calculate duration in nanoseconds
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    std::cout << "Time taken to sort " << n << " elements: " << duration.count() << " nanoseconds" << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of elements to sort: ";
    std::cin >> n;

    measureTime(n);
    return 0;
}
