//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/532/week-5/3315/

// 典型dfs题目
// 非常需要注意的地方还是题目
// [8,3,null,2,1,5,4] [8] 这个样例没过因为题目中要求的是 最后的节点一定要是叶子节点

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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if(root == NULL) return false;
        return isValidSequence(root, arr, 0);
    }
private:
    bool isValidSequence(TreeNode* root, vector<int>& arr, int index){
        if(root == NULL){
            return false;
        }else if(root->right == NULL && root->left == NULL){
            if(index == arr.size()-1 && arr[index] == root->val) return true;
            else return false;
        }
        if(index < arr.size()){
            return root->val == arr[index] ? (isValidSequence(root->right, arr, index+1)||isValidSequence(root->left,arr, index+1)) :false;
        }
        else return false;
    }
};

// dfs 

// 欣赏dl concise & beautiful方法
// dfs && bfs

// BFS using stack
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if(!root || arr.empty())
            return false;
        
        std::stack<std::pair<TreeNode*, unsigned int>> q;
        q.push({root, 0});
        
        for(;!q.empty();){
            
            auto [root, index] = q.top();
            q.pop();
            if(index == arr.size() || root->val != arr[index])
                continue;
            
            if((index+1) == arr.size() && !root->left && !root->right) 
                return true;
            
            if(root->left)
                q.push({root->left, index+1});
            if(root->right)
                q.push({root->right, index+1});
        }
        
        return false;
}

// DFS using recursive
   bool isValidSequence(TreeNode* root, vector<int>& arr, const unsigned int index = 0) {
        if(!root || index == arr.size() || root->val != arr[index])
            return false;
        
        if( (index+1) == arr.size() )
            return !root->left && !root->right ? true : false;
        
        return isValidSequence(root->left, arr, index+1) || isValidSequence(root->right, arr, index+1);
    }
    
