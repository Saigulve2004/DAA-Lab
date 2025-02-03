#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

// Karatsuba multiplication (using only int and no strings)
int karatsuba(int x, int y) {
    if (x < 10 || y < 10) {
        return x * y;
    }

    // Determine the number of digits in the larger number
    int temp_x = x, temp_y = y;
    int n_x = 0, n_y = 0;

    while (temp_x > 0) {
        temp_x /= 10;
        n_x++;
    }
    while (temp_y > 0) {
        temp_y /= 10;
        n_y++;
    }
    int n = max(n_x, n_y);
    n = (n + 1) / 2;

    int power_of_10 = pow(10, n); // Potential Overflow Here!!!

    // Split the numbers into two halves
    int a = x / power_of_10;
    int b = x % power_of_10;
    int c = y / power_of_10;
    int d = y % power_of_10;

    // Recursively calculate the three products
    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);
    int ad_bc = karatsuba(a + b, c + d) - ac - bd;

    // Combine the results
    return ac * (int)pow(10, 2 * n) + ad_bc * (int)pow(10, n) + bd; // Potential Overflow Here!!!
}

int main() {
    int num1, num2;

    cout << "Enter the first integer: ";
    cin >> num1;
    cout << "Enter the second integer: ";
    cin >> num2;

    auto start = high_resolution_clock::now();
    int result = karatsuba(num1, num2);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Product: " << result << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;

    return 0;
}
