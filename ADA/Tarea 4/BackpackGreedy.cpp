#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item a, Item b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}

double greedyKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (const Item& item : items) {
        if (currentWeight + item.weight <= capacity) {
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += item.value * ((double)remainingWeight / item.weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity = 50;
    vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120}
    };

    double maxValue = greedyKnapsack(capacity, items);

    cout << "El valor máximo obtenido es: " << maxValue << endl;

    return 0;
}
