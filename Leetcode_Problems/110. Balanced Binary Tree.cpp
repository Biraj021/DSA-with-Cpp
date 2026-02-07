// Given a binary tree, determine if it is height-balanced.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: true
// Example 2:


// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// Example 3:

// Input: root = []
// Output: true
 

// Constraints:

// The number of nodes in the tree is in the range [0, 5000].
// -104 <= Node.val <= 104
class Solution {
public:
int levels(TreeNode* root){
if(root==NULL) return 0;
return 1 + max(levels(root->left),levels(root->right));
}
bool isBalanced(TreeNode* root) {
if(root==NULL) return true;
int left = levels(root->left);
int right = levels(root->right);
int diff = abs(left - right);
if(diff>1) return false;
bool leftTreeAns = isBalanced(root->left);
if(leftTreeAns==false) return false;
bool rightTreeAns = isBalanced(root->right);
if(rightTreeAns==false) return false;
return true;
}
};
