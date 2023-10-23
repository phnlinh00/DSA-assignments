#include <iostream>
#include <string>
using namespace std;

void displayAllBinaryNums(int n, string current) {
    if (n == 0) {
        cout << current << endl;
    } else {
    displayAllBinaryNums(n - 1, current + '0');
    displayAllBinaryNums(n - 1, current + '1');
    }
}

int main() {
    int n;
    cin >> n;
    displayAllBinaryNums(n, "");
    return 0;
}
