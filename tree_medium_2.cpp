// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3398/
// 层次遍历总是一遍AC，好爽~

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> p;
        if(root == NULL) return p;
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        int cursz;
        TreeNode* temp = root;
        int level = 0;
        while(!treeQueue.empty()){
            cursz = treeQueue.size();
            level++;
            vector<int> tempv;
            while(cursz--){
                temp = treeQueue.front();
                if(temp->left != NULL){
                    treeQueue.push(temp->left);
                }
                if(temp->right != NULL){
                    treeQueue.push(temp->right);
                }
                if(level %2 == 0) tempv.insert(tempv.begin(), temp->val);
                else tempv.push_back(temp->val);
                treeQueue.pop();
            }
            p.push_back(tempv);
        }
        return p;
    }
};