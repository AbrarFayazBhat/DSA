/*Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the minimum element using binary search
    int findMin(vector<int>& nums) {

        // Initialize low and high pointers
        int low = 0, high = nums.size() - 1;

        // Binary search loop
        while (low < high) {

            // Calculate mid index
            int mid = low + (high - low) / 2;

            // Check which half to discard
            if (nums[mid] > nums[high]) {

                // Minimum lies in right half
                low = mid + 1;

            } else {

                // Minimum lies in left half (including mid)
                high = mid;
            }
        }

        // Return the minimum element
        return nums[low];
    }
};

int main() {

    // Input array
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    // Create object of Solution
    Solution sol;

    // Call function and store result
    int result = sol.findMin(nums);

    // Output the result
    cout << "Minimum element is " << result << endl;

    return 0;
}