#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Activity {
    int start, finish;
};

// Partition function for QuickSort (sorting by finish time)
int partition(Activity arr[], int low, int high) {
    Activity pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].finish < pivot.finish) {
            i++;
            // Swap arr[i] and arr[j]
            Activity temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i + 1] and arr[high] (or pivot)
    Activity temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// QuickSort function
void quickSort(Activity arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print maximum number of non-overlapping activities
void printMaxActivities(Activity arr[], int n) {
    quickSort(arr, 0, n - 1); // Sorting activities based on finish time

    cout << "Following activities are selected:\n";

    int i = 0; // The first activity is always selected
    cout << "(" << arr[i].start << ", " << arr[i].finish << ")";

    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            cout << ", (" << arr[j].start << ", " << arr[j].finish << ")";
            i = j; // Update the last selected activity
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    Activity arr[n];

    cout << "Enter start and finish times of activities:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].finish;
    }

    auto start = high_resolution_clock::now();

    printMaxActivities(arr, n);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Execution time: " << duration.count() << " microseconds\n";

    return 0;
}
