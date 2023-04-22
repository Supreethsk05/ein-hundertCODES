#include <iostream>
#include <vector>
using namespace std;
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}

int main() {
    vector<int> nums1 = {2, 2, 1};
    cout << "The single element in {2, 2, 1} is " << singleNumber(nums1) << endl;

    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "The single element in {4, 1, 2, 1, 2} is " << singleNumber(nums2) << endl;

    return 0;
}
