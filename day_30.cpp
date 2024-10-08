#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    // Create a dp array to store the minimum number of coins for each amount from 0 to amount
    vector<int> dp(amount + 1, INT_MAX);

    dp[0] = 0;

    for (int coin : coins) {
        // Update the dp array for all amounts from the coin's value to the target amount
        for (int i = coin; i <= amount; i++) {
            // If we can form (i - coin), then we can form i by adding this coin
            if (dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    // If the amount cannot be formed, return -1
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}


//Main Function
int main() {
    vector<int> coins = {1, 2, 5};
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    int result = minCoins(coins, amount);
    if (result == -1) {
        cout << "It is not possible to make the amount with the given coins" << endl;
    } else {
        cout << "The minimum number of coins required is: " << result << endl;
    }
    return 0;
}
