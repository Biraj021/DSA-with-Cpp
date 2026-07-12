// You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

// Each minute, a node becomes infected if:

// The node is currently uninfected.
// The node is adjacent to an infected node.
// Return the number of minutes needed for the entire tree to be infected.

 

// Example 1:


// Input: root = [1,5,3,null,4,10,6,9,2], start = 3
// Output: 4
// Explanation: The following nodes are infected during:
// - Minute 0: Node 3
// - Minute 1: Nodes 1, 10 and 6
// - Minute 2: Node 5
// - Minute 3: Node 4
// - Minute 4: Nodes 9 and 2
// It takes 4 minutes for the whole tree to be infected so we return 4.
// Example 2:


// Input: root = [1], start = 1
// Output: 0
// Explanation: At minute 0, the only node in the tree is infected so we return 0.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 105].
// 1 <= Node.val <= 105
// Each node has a unique value.
// A node with a value of start exists in the tree.
class Solution {
public:
    TreeNode* first = NULL;
    void markparent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        if(root == NULL) return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        markparent(root->left, parent);
        markparent(root->right, parent);
    }
    void find(TreeNode* root, int start){
        if(root == NULL) return;
        if(root->val == start){
            first = root;
            return;
        }
        find(root->left, start);
        find(root->right, start);
    }
    int amountOfTime(TreeNode* root, int start) {
        find(root, start);
        if(first == NULL) return 0; 
        unordered_map<TreeNode*, TreeNode*> parent;
        markparent(root, parent); 
        unordered_set<TreeNode*> s;
        s.insert(first);
        queue<pair<TreeNode*, int>> q;
        q.push({first, 0});
        int maxlevel = 0;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* temp = p.first;
            int level = p.second;
            maxlevel = max(maxlevel, level);
            if(temp->left && s.find(temp->left) == s.end()){
                q.push({temp->left, level + 1});
                s.insert(temp->left);
            }
            if(temp->right && s.find(temp->right) == s.end()){
                q.push({temp->right, level + 1});
                s.insert(temp->right);
            }
            if(parent[temp] && s.find(parent[temp]) == s.end()){
                q.push({parent[temp], level + 1});
                s.insert(parent[temp]);
            }
        }
        return maxlevel;
    }
};
