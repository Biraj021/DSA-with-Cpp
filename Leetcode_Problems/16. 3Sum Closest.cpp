// Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

 

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

// Constraints:

// 3 <= nums.length <= 500
// -1000 <= nums[i] <= 1000
// -104 <= target <= 104
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, h = n - 1;
            while (l < h) {
                int currSum = nums[i] + nums[l] + nums[h];
                if (abs(currSum - target) < abs(closestSum - target)) {
                    closestSum = currSum;
                }
                if (currSum < target) {
                    l++;
                } else if (currSum > target) {
                    h--;
                } else {
                    return currSum;
                }
            }
        }
        return closestSum;
    }
};
