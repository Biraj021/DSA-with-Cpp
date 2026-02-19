// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

// Example 1:

// Input: root = [1,2,3,null,5,null,4]

// Output: [1,3,4]

// Explanation:



// Example 2:

// Input: root = [1,2,3,4,null,null,null,5]

// Output: [1,3,4,5]

// Explanation:



// Example 3:

// Input: root = [1,null,3]

// Output: [1,3]

// Example 4:

// Input: root = []

// Output: []

 

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
class Solution {
public:
int levels(TreeNode* root){
    if(root==NULL) return 0;
    return 1+max(levels(root->left),levels(root->right));
}
void preorder(TreeNode* root,vector<int>& ans,int level){
    if(root==NULL) return;
    ans[level]=root->val;
    preorder(root->left,ans,level+1);
    preorder(root->right,ans,level+1);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans(levels(root),0);
        preorder(root,ans,0);
        return ans;
    }
};