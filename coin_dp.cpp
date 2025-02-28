#include <iostream>
using namespace std;

void coinChange(int coins[], int numCoins, int amount) {
    // Create a DP array with (amount + 1) elements initialized to 0
    int dp[amount + 1] = {0};
    
    // There is one way to make the amount 0: use no coins
    dp[0] = 1;
    
    // Iterate over each coin
    for (int i = 0; i < numCoins; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    
    // The answer is the number of ways to make the amount
    cout << "Number of ways to make amount " << amount << " is: " << dp[amount] << endl;
}

int main() {
    int coins[10]; // Array to hold coin denominations (max 10 denominations)
    int numCoins = 0;
    int amount;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter coin denominations\n";
        cout << "2. Enter amount\n";
        cout << "3. Calculate number of ways to make the amount\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of coin denominations (max 10): ";
                cin >> numCoins;
                cout << "Enter the coin denominations:\n";
                for (int i = 0; i < numCoins; i++) {
                    cin >> coins[i];
                }
                break;

            case 2:
                cout << "Enter the amount: ";
                cin >> amount;
                break;

            case 3:
                if (numCoins == 0) {
                    cout << "Please enter coin denominations first.\n";
                } else if (amount < 0) {
                    cout << "Please enter a valid amount.\n";
                } else {
                    coinChange(coins, numCoins, amount);
                }
                break;

            case 4:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
