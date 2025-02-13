#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to sort jobs in descending order of profit (Manual Bubble Sort)
void sortJobs(int profits[], int deadlines[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (profits[j] < profits[j + 1]) {
                // Swap profits
                int tempProfit = profits[j];
                profits[j] = profits[j + 1];
                profits[j + 1] = tempProfit;

                // Swap corresponding deadlines
                int tempDeadline = deadlines[j];
                deadlines[j] = deadlines[j + 1];
                deadlines[j + 1] = tempDeadline;
            }
        }
    }
}

// Function to find the maximum deadline
int findMaxDeadline(int deadlines[], int n) {
    int maxDeadline = 0;
    for (int i = 0; i < n; ++i) {
        if (deadlines[i] > maxDeadline) {
            maxDeadline = deadlines[i];
        }
    }
    return maxDeadline;
}

// Function to schedule jobs to maximize profit
int jobScheduling(int profits[], int deadlines[], int n) {
    // Step 1: Sort jobs in descending order of profit
    sortJobs(profits, deadlines, n);

    // Step 2: Find the maximum deadline
    int maxDeadline = findMaxDeadline(deadlines, n);

    // Step 3: Create an array to keep track of free slots
    int schedule[maxDeadline + 1]; // 1-based indexing
    for (int i = 0; i <= maxDeadline; ++i) {
        schedule[i] = -1; // -1 means slot is empty
    }

    // Step 4: Assign jobs to slots
    int totalProfit = 0;
    int jobsCount = 0;

    for (int i = 0; i < n; ++i) {
        // Try to schedule job at the last possible slot
        for (int j = deadlines[i]; j > 0; --j) {
            if (schedule[j] == -1) {
                schedule[j] = i;
                totalProfit += profits[i];
                jobsCount++;
                break;
            }
        }
    }

    // Display scheduled jobs
    cout << "Scheduled Jobs: ";
    for (int i = 1; i <= maxDeadline; ++i) {
        if (schedule[i] != -1) {
            cout << "(" << profits[schedule[i]] << ", " << deadlines[schedule[i]] << ") ";
        }
    }
    cout << endl;

    return totalProfit;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    int profits[n], deadlines[n];

    cout << "Enter profits: ";
    for (int i = 0; i < n; ++i) {
        cin >> profits[i];
    }

    cout << "Enter deadlines: ";
    for (int i = 0; i < n; ++i) {
        cin >> deadlines[i];
    }

    // Start measuring time
    auto start_time = high_resolution_clock::now();

    int maxProfit = jobScheduling(profits, deadlines, n);

    // Stop measuring time
    auto end_time = high_resolution_clock::now();
    
    // Calculate duration
    auto duration = duration_cast<microseconds>(end_time - start_time);

    cout << "Maximum Profit: " << maxProfit << endl;
    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}

