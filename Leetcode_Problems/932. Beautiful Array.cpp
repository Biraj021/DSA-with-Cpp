// An array nums of length n is beautiful if:

// nums is a permutation of the integers in the range [1, n].
// For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
// Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.

 

// Example 1:

// Input: n = 4
// Output: [2,1,4,3]
// Example 2:

// Input: n = 5
// Output: [3,1,2,5,4]
 

// Constraints:

// 1 <= n <= 1000
class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans;
        ans.push_back(1);   // start with 1

        while (ans.size() < n) {
            vector<int> temp;

            // generate odd numbers
            for (int x : ans) {
                if (2 * x - 1 <= n)
                    temp.push_back(2 * x - 1);
            }

            // generate even numbers
            for (int x : ans) {
                if (2 * x <= n)
                    temp.push_back(2 * x);
            }

            ans = temp;
        }

        return ans;
    }
};
