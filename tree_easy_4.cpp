//https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/628/
//tree 方面有点不熟练，有点不知道怎么使用有些量

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        int curlevelsz = 0;
        
        q.push(root);
        TreeNode* temp;
        
        while(!q.empty()){
            curlevelsz = q.size();
            vector<int> level;
            while(curlevelsz--){
                temp = q.front();
                level.push_back(temp->val);
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                q.pop();
            }
            res.push_back(level);
        }
        return res;
    }
};

// 这个方法比较easy & a little waste memory 
// 相当是用层次遍历的方法，思想去解决问题，然后统计好curlevelsz 现在所在层的大小，借助queue完成（虽然这样费了空间）
// 开始自己的思路一直卡在curlevelsz 怎么统计上面，感觉有点不知道如何计算
// 以后有机会再看下其他更好的思路
