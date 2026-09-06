//HARSHIT SAH 25/DA/032
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight, value;
    double ratio;
};

int main() {
    int n, capacity;
    cin >> n >> capacity;

    vector<Item> items(n);

    for(int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio;
    });

    double maxValue = 0.0;

    for(int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            maxValue += items[i].value;
        } else {
            maxValue += items[i].ratio * capacity;
            break;
        }
    }

    cout << fixed << setprecision(2) << maxValue << '\n';

    return 0;
}
