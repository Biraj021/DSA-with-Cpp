// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
// Example 2:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of only uppercase English letters.
// 0 <= k <= s.length
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);   // frequency of A-Z
        int left = 0;
        int maxFreq = 0;           // highest frequency in current window
        int maxLength = 0;

        for(int right = 0; right < s.length(); right++) {
            // increase frequency of current character
            count[s[right] - 'A']++;

            // update max frequency
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            // if window invalid, shrink from left
            while((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            // update maximum length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
