#include <iostream>
#include <vector>
using namespace std;

void greedyCoinChange(int amount, vector<int> coins) {
    vector<int> result;
    for (int i = coins.size() - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            result.push_back(coins[i]);
            amount -= coins[i];
        }
    }
    if (amount == 0) {
        cout << "El cambio óptimo es: ";
        for (int coin : result) {
            cout << coin << " ";
        }
        cout << endl;
    } else {
        cout << "No se puede dar cambio exacto." << endl;
    }
}

int main() {
    int amount = 78;
    vector<int> coins = {1, 5, 10, 25};
    greedyCoinChange(amount, coins);
    return 0;
}
