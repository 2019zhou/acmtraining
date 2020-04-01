//https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/625/

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
private:
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max){
        if(!root) return true;
        if(min && min->val >= root->val || max && max->val <= root->val)  return false;
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
};


// medium难度
// 这个思路非常的巧妙，用的是递归，从每一个节点考虑问题，root 节点是(-∞，+∞),left tree的范围(-∞, val)
// 用Null来表示∞，因为如果使用的是INT_MAX, INT_MIN测试样例会有极端值，如INT_MAX, INT_MIN的出现，导致过不了
// 如果使用LLONG_MIN, LLONG_MAX 会导致平台不适配，只要val不是int就会出问题
