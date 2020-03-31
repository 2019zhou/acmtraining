//find the maxDepth of the tree 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};

//要考虑是空树的情况
