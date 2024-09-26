#include <iostream>
#include <cmath>
using namespace std;

// Function to display all prime factors of a given number
void print_Prime_Factors(int number) {
    // Step 1: Deal with factors of 2 separately
    while (number % 2 == 0) {
        cout << 2 << " ";
        number /= 2;
    }

    // Step 2: Check odd numbers from 3 upwards for divisibility
    for (int i = 3; i <= sqrt(number); i += 2) {
        while (number % i == 0) {
            cout << i << " ";
            number /= i;
        }
    }
    // Step 3: If the remaining number is greater than 2, it must be prime
    if (number > 2)
        cout << number << " ";
}

//Main Function
int main() {
    int number =18;
    print_Prime_Factors(number);
    return 0;
}
