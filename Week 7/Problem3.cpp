#include <iostream>
using namespace std;

int greatestCommonDivisor(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return greatestCommonDivisor(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << greatestCommonDivisor(a, b);
}