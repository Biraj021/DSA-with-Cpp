// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

// Example 1:


// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:


// Input: heights = [2,4]
// Output: 4
 

// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();

        // Next Smaller Index (NSI)
        vector<int> nsi(n);
        stack<int> s;  // stack for NSI
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            if (s.empty())
                nsi[i] = n;    // if no smaller to right
            else
                nsi[i] = s.top(); // next smaller index
            s.push(i);
        }

        // Previous Smaller Index (PSI)
        vector<int> psi(n);
        stack<int> t;  // stack for PSI
        for (int i = 0; i < n; i++) {
            while (!t.empty() && arr[t.top()] >= arr[i]) t.pop();
            if (t.empty())
                psi[i] = -1;   // if no smaller to left
            else
                psi[i] = t.top(); // previous smaller index
            t.push(i);
        }

        // Calculate max area
        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            int height = arr[i];
            int breadth = nsi[i] - psi[i] - 1;
            int area = height * breadth;
            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};