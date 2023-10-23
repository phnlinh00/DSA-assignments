#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void displayAllPermutations(int n, vector<int>& current, vector<bool>& selected) {
    if (current.size() == n) {
        for (int num : current) {
            cout << num;
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!selected[i]) {
            selected[i] = true;
            current.push_back(i);

            displayAllPermutations(n, current, selected);

            selected[i] = false;
            current.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> current;
    vector<bool> selected(n + 1, false);

    displayAllPermutations(n, current, selected);

    return 0;
}
