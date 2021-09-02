//https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
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
private:
    int maxSum(TreeNode * root, int & ans){
        if(!root) return 0;
        int l = max(0, maxSum(root->left, ans));
        int r = max(0, maxSum(root->right, ans));
        int sum = l + r + root-> val;
        ans = max(ans, sum);
        return max(l, r) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MIN;
        maxSum(root, ans);
        return ans;
    }
};
