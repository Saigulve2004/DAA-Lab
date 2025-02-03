#include <iostream>
#include <chrono>
#include <cstdlib> // For rand and srand
#include <ctime>   // For time

using namespace std;
using namespace std::chrono;

// Merge function (without vector)
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// Merge Sort function (without vector)
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n]; // Dynamically allocate the array

    // Generate random numbers (without algorithm)
    srand(time(0)); // Seed the random number generator

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Generates numbers between 0 and 9999
    }

    auto start = high_resolution_clock::now();

    mergeSort(arr, 0, n - 1);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Time taken for Merge Sort: " << duration.count() << " nanoseconds" << endl;

    // Optional: Print the first few elements to verify (for smaller n)
    /*
    if (n <= 20) {
        cout << "Sorted array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    */

    delete[] arr; // Deallocate the dynamically allocated array. VERY IMPORTANT!
    return 0;
}
