#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    vector<int> candies(5);
    for (int i = 0; i < 5; ++i) {
        cin >> candies[i];
    }
    for (int i = 0; i < 5; ++i) {
        int current = candies[i];
        int share = current / 3;
        candies[i] = share;
        int left = (i - 1 + 5) % 5;
        candies[left] += share;
        int right = (i + 1) % 5;
        candies[right] += share;
    }

    for (int i = 0; i < 5; ++i) {
        cout << setw(5) << candies[i];
    }
    cout << endl;

    return 0;
}