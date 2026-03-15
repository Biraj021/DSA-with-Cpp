// A magical string s consists of only '1' and '2' and obeys the following rule:

// Concatenating the sequence of lengths of its consecutive groups of identical characters '1' and '2' generates the string s itself.
// The first few elements of s is s = "1221121221221121122……". If we group the consecutive 1's and 2's in s, it will be "1 22 11 2 1 22 1 22 11 2 11 22 ......" and counting the occurrences of 1's or 2's in each group yields the sequence "1 2 2 1 1 2 1 2 2 1 2 2 ......".

// You can see that concatenating the occurrence sequence gives us s itself.

// Given an integer n, return the number of 1's in the first n number in the magical string s.

 

// Example 1:

// Input: n = 6
// Output: 3
// Explanation: The first 6 elements of magical string s is "122112" and it contains three 1's, so return 3.
// Example 2:

// Input: n = 1
// Output: 1
 

// Constraints:

// 1 <= n <= 10
class Solution {
public:
    int magicalString(int n) {
        if (n == 0) return 0;
        if (n <= 3) return 1; // "122" has 1 one

        vector<int> s = {1, 2, 2};
        int count = 1; // count of 1's
        int i = 2;     // pointer to read
        int nextNum = 1;

        while (s.size() < n) {
            int times = s[i];
            for (int j = 0; j < times && s.size() < n; j++) {
                s.push_back(nextNum);
                if (nextNum == 1) count++;
            }
            nextNum = 3 - nextNum; // alternate 1 <-> 2
            i++;
        }

        return count;
    }
};
