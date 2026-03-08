// Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

// It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

// A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

// A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

 

// Example 1:


// Input: preorder = [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]
// Example 2:

// Input: preorder = [1,3]
// Output: [1,null,3]
 

// Constraints:

// 1 <= preorder.length <= 100
// 1 <= preorder[i] <= 1000
// All the values of preorder are unique.
class Solution {
public:
    TreeNode* insert(TreeNode* root, int val) {
        if (root == NULL)
            return new TreeNode(val);

        if (val < root->val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& pre) {
        if (pre.empty()) return NULL;

        TreeNode* root = new TreeNode(pre[0]);
        for (int i = 1; i < pre.size(); i++) {
            insert(root, pre[i]);
        }
        return root;
    }
};
