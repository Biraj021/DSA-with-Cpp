// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

// Example 1:


// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: inorder = [-1], postorder = [-1]
// Output: [-1]
 

// Constraints:

// 1 <= inorder.length <= 3000
// postorder.length == inorder.length
// -3000 <= inorder[i], postorder[i] <= 3000
// inorder and postorder consist of unique values.
// Each value of postorder also appears in inorder.
// inorder is guaranteed to be the inorder traversal of the tree.
// postorder is guaranteed to be the postorder traversal of the tree.
class Solution {
public:
    TreeNode* build(vector<int>& in,int inlo,int inhi,vector<int>& pos,int poslo,int poshi){
        if(poslo>poshi) return NULL;
        TreeNode* root = new TreeNode(pos[poshi]);
        if(poslo==poshi) return root;
        int i=inlo;
        while(i<=inhi){
            if(in[i]==pos[poshi]) break;
            i++;
        }
        int leftcount=i-inlo;
        int rightcount=inhi-i;
        root->left=build(in,inlo,i-1,pos,poslo,poslo+leftcount-1);
        root->right=build(in,i+1,inhi,pos,poslo+leftcount,poshi-1);
        return root;
     }
    TreeNode* buildTree(vector<int>& in, vector<int>& pos) {
        int n=in.size();
        return build(in,0,n-1,pos,0,n-1);
    }
};