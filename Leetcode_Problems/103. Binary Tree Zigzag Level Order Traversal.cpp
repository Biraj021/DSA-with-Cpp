// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -100 <= Node.val <= 100
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    void nthlevel(TreeNode* root, int curr, int level, vector<int>& v) {
        if (root == NULL) return;
        if (curr == level) {
            v.push_back(root->val);
            return;
        }
        if(level%2!=0){
        nthlevel(root->left, curr + 1, level, v);
        nthlevel(root->right, curr + 1, level, v);
        }
        else{
        nthlevel(root->right, curr + 1, level, v);
        nthlevel(root->left, curr + 1, level, v);
        }
        
    }
    void lorder(TreeNode* root, vector<vector<int>>& ans) {
        int n = height(root);
        for (int i = 1; i <= n; i++) {
            vector<int> v;
            nthlevel(root, 1, i, v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    lorder(root,ans);
    return ans;
    }
};