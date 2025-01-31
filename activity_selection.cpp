#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;

// A job has a start time and finish time.
struct Activity {
    int start, finish;
};

// A utility function that is used for sorting
// activities according to finish time using Selection Sort
void selectionSort(Activity arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].finish < arr[minIndex].finish) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void printMaxActivities(Activity arr[], int n) {
    // Sort activities according to finish time
    selectionSort(arr, n);

    cout << "Following activities are selected:\n";

    // The first activity always gets selected
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << ")";

    // Consider rest of the activities
    for (int j = 1; j < n; j++) {
        // If this activity has start time greater than or
        if (arr[j].start >= arr[i].finish) {
            cout << ", (" << arr[j].start << ", " << arr[j].finish << ")";
            i = j;
        }
    }
}

// Driver code
int main() {
    Activity arr[] = { { 5, 9 }, { 1, 2 }, { 3, 4 },
                       { 0, 6 }, { 5, 7 }, { 8, 9 } };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    printMaxActivities(arr, n);
    return 0;
}
