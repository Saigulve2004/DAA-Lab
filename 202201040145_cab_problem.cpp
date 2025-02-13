#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Custom function to sort an array using Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the minimum number of cabs required
int minCabsRequired(int n, int start[], int end[]) {
    bubbleSort(start, n);
    bubbleSort(end, n);

    int cabs = 0, maxCabs = 0;
    int i = 0, j = 0;

    while (i < n) {
        if (start[i] <= end[j]) { 
            cabs++; 
            if (cabs > maxCabs)
                maxCabs = cabs;
            i++;
        } else { 
            cabs--; 
            j++;
        }
    }
    return maxCabs;
}

int main() {
    int n;
    cout << "Enter number of persons: ";
    cin >> n;

    int start[n], end[n];

    cout << "Enter start times: ";
    for (int i = 0; i < n; i++)
        cin >> start[i];

    cout << "Enter end times: ";
    for (int i = 0; i < n; i++)
        cin >> end[i];

    auto start_time = high_resolution_clock::now();

    int result = minCabsRequired(n, start, end);
    
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end_time - start_time);

    cout << "Minimum number of cabs required: " << result << endl;
    cout << "Execution time: " << duration.count() << " mnanoseconds" << endl;

    return 0;
}

