#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int left, int right, int pivot) {
    while (left <= right) {
        while (nums[left] < pivot) {
            left++;
        }

        while(nums[right] > pivot) {
            right--;
        }
        
        if (left <= right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
    return left;
}


void quickSort(vector<int>& nums, int left, int right) {
    if (left < right) {
        int pivot = nums[left + (right - left) / 2];
        int index = partition(nums, left, right, pivot);
        
        quickSort(nums, left, index - 1);
        quickSort(nums, index, right);
    } else {
        return;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (auto& it : nums) {
        cin >> it;
    }

    quickSort(nums, 0, n - 1);

    for (auto it : nums) {
        cout << it << " ";
    }

    return 0;
}
