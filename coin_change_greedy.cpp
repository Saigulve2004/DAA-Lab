#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to sort the coin denominations in descending order using Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx])
                maxIdx = j;
        }
        swap(arr[i], arr[maxIdx]);
    }
}

// Function to find the minimum number of coins needed
void minCoins(int coins[], int n, int amount) {
    selectionSort(coins, n); // Sort the coins in descending order

    int count = 0;
    cout << "Coins used to make change for " << amount << ": ";
    
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            cout << coins[i] << " ";
            count++;
        }
    }

    cout << "\nMinimum number of coins required: " << count << endl;
}

// Driver function
int main() {
    int n, amount;
    
    cout << "Enter the number of denominations: ";
    cin >> n;
    
    int coins[n];
    cout << "Enter the denominations: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter the amount to make change for: ";
    cin >> amount;

    auto start = high_resolution_clock::now(); // Start time measurement

    minCoins(coins, n, amount);

    auto end = high_resolution_clock::now(); // End time measurement
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Execution time: " << duration.count() << " microseconds\n";

    return 0;
}

