// You are given a string array words, consisting of distinct 4-letter strings, each containing lowercase English letters.

// A word square consists of 4 distinct words: top, left, right and bottom, arranged as follows:

// top forms the top row.
// bottom forms the bottom row.
// left forms the left column (top to bottom).
// right forms the right column (top to bottom).
// It must satisfy:

// top[0] == left[0], top[3] == right[0]
// bottom[0] == left[3], bottom[3] == right[3]
// Return all valid distinct word squares, sorted in ascending lexicographic order by the 4-tuple (top, left, right, bottom)​​​​​​​.

 

// Example 1:

// Input: words = ["able","area","echo","also"]

// Output: [["able","area","echo","also"],["area","able","also","echo"]]

// Explanation:

// There are exactly two valid 4-word squares that satisfy all corner constraints:

// "able" (top), "area" (left), "echo" (right), "also" (bottom)
// top[0] == left[0] == 'a'
// top[3] == right[0] == 'e'
// bottom[0] == left[3] == 'a'
// bottom[3] == right[3] == 'o'
// "area" (top), "able" (left), "also" (right), "echo" (bottom)
// All corner constraints are satisfied.
// Thus, the answer is [["able","area","echo","also"],["area","able","also","echo"]].

// Example 2:

// Input: words = ["code","cafe","eden","edge"]

// Output: []

// Explanation:

// No combination of four words satisfies all four corner constraints. Thus, the answer is empty array [].

 

// Constraints:

// 4 <= words.length <= 15
// words[i].length == 4
// words[i] consists of only lowercase English letters.
// All words[i] are distinct.
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<string> sorivandek = words;
        vector<vector<string>> ans;
        int n = sorivandek.size();
        for (int i = 0; i < n; i++) {         
            for (int j = 0; j < n; j++) {      
                if (j == i) continue;
                for (int k = 0; k < n; k++) { 
                    if (k == i || k == j) continue;
                    for (int l = 0; l < n; l++) { 
                        if (l == i || l == j || l == k) continue;
                        string top = sorivandek[i];
                        string left = sorivandek[j];
                        string right = sorivandek[k];
                        string bottom = sorivandek[l];
                        if (top[0] == left[0] &&
                            top[3] == right[0] &&
                            bottom[0] == left[3] &&
                            bottom[3] == right[3]) {
                            ans.push_back({top, left, right, bottom});
                        }
                    }
                }
            }

        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};