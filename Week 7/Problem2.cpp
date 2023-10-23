#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ifstream input("matrix.txt");
    ofstream output("matrix.out");

    if (!input.is_open() || !output.is_open()) {
        cerr << "Failed to open files\col";
        return 1;
    }

    int row, col;
    input >> row >> col;
    vector<vector<int>> matrix(row, vector<int>(col));

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            input >> matrix[i][j];
        }
    }

    int maxSum = INT_MIN;
    int finalLeft, finalRight, finalTop, finalBottom;

    for (int left = 0; left < col; ++left) {
        vector<int> temp(row, 0);

        for (int right = left; right < col; ++right) {
            for (int i = 0; i < row; ++i) {
                temp[i] += matrix[i][right];
            }

            int sum = INT_MIN;
            int start, finish;
            int localStart = 0;

            for (int i = 0; i < row; ++i) {
                if (sum < 0) {
                    sum = temp[i];
                    localStart = i;
                } else {
                    sum += temp[i];
                }
                if (sum > maxSum) {
                    maxSum = sum;
                    finalLeft = left;
                    finalRight = right;
                    finalTop = localStart;
                    finalBottom = i;
                }
            }
        }
    }

    output << finalTop + 1 << " " << finalLeft + 1 << " " << finalBottom + 1 
    << " " << finalRight + 1 << " " << maxSum << endl;

    input.close();
    output.close();

    return 0;
}
