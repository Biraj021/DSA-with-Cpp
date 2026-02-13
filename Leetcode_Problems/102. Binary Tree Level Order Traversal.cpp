// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000
class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    void nthlevel(TreeNode* root, int curr, int level, vector<int>& v) {
        if (root == nullptr) return;
        if (curr == level) {
            v.push_back(root->val);
            return;
        }
        nthlevel(root->left, curr + 1, level, v);
        nthlevel(root->right, curr + 1, level, v);
    }
    void lorder(TreeNode* root, vector<vector<int>>& ans) {
        int n = height(root);
        for (int i = 1; i <= n; i++) {
            vector<int> v;
            nthlevel(root, 1, i, v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        lorder(root, ans);
        return ans;
    }
};