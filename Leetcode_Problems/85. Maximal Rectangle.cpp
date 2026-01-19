// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1
 

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 1 <= rows, cols <= 200
// matrix[i][j] is '0' or '1'.
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsi(n), psi(n);
        stack<int> st;

        // Next Smaller Index
        nsi[n - 1] = n;
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nsi[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Previous Smaller Index
        while (!st.empty()) st.pop();
        psi[0] = -1;
        st.push(0);
        for (int i = 1; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            psi[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int height = arr[i];
            int width = nsi[i] - psi[i] - 1;
            maxArea = max(maxArea, height * width);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& a) {
        if (a.empty()) return 0;

        int n = a.size();
        int m = a[0].size();
        vector<int> row(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '1')
                    row[j]++;
                else
                    row[j] = 0;
            }
            maxArea = max(maxArea, largestRectangleArea(row));
        }
        return maxArea;
    }
};
