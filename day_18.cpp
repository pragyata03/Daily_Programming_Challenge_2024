#include <iostream>
#include <cmath>
using namespace std;

// Function to mark primes and squares of primes
void mark_Primes(int n, bool prime[], bool prime_square[], int primes[]) {
    for (int i = 2; i <= n; i++)
        prime[i] = true;
    
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }

    int idx = 0;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            primes[idx++] = i;
            prime_square[i * i] = true;
        }
    }
}

// Function to count divisors
int count_Divisors(int n) {
    if (n == 1)
        return 1;

    bool prime[n + 1], prime_square[n * n + 1] = {false};
    int primes[n], divisor_Count = 1;

    mark_Primes(n, prime, prime_square, primes);

    for (int i = 0; primes[i] * primes[i] * primes[i] <= n; i++) {
        int power = 1;
        while (n % primes[i] == 0) {
            n /= primes[i];
            power++;
        }
        divisor_Count *= power;
    }

    if (prime[n])
        divisor_Count *= 2;
    else if (prime_square[n])
        divisor_Count *= 3;
    else if (n != 1)
        divisor_Count *= 4;

    return divisor_Count;
}

//Main Function
int main() {
    cout << "Total distinct divisors of 12: " << count_Divisors(12) << endl;
    return 0;
}
