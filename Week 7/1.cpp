#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void selectionSort(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        swap(nums[i], nums[minIndex]);
    }
}

void insertionSort(vector<int> &nums) {
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        int j = i;
        while (nums[j] < nums[j - 1] && j > 0) {
            swap(nums[j], nums[j - 1]);
            j--;
        }
    }
}

void bubbleSort(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    ifstream input("numbers.txt");
    ofstream output("number.sorted");

    if (!input.is_open() || !output.is_open()) {
        cerr << "Failed to open files\n";
        return 1;
    }

    vector<int> nums;
    int num;
    while(input >> num) {
        nums.push_back(num);
    }
    
    selectionSort(nums);
    // insertionSort(nums);
    // bubbleSort(nums);

    for (auto it : nums) {
        output << it << " ";
    }
    input.close();
    output.close();

    return 0;
}
