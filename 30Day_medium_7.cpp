//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/


// 直接AC,开心了！！

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
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* temp = root;
        queue<TreeNode*> qu;
        qu.push(root);
        int cursz;
        bool xhere = false;
        bool yhere = false;
        bool status = false;
        while(!qu.empty()){
            cursz = qu.size();
            while(cursz--){
                temp = qu.front();
                if(xhere^yhere) status = true;
                if(temp->left!= NULL){
                    qu.push(temp->left);
                    if(temp->left->val == x) xhere = true;
                    if(temp->left->val == y) yhere = true;
                }
                if(temp->right!= NULL){
                    qu.push(temp->right);
                    if(temp->right->val == x) xhere = true;
                    if(temp->right->val == y) yhere = true;
                }
                if(status == false && xhere&&yhere) return false;
                qu.pop();
            }
            if(xhere&&yhere) return true;
            else{xhere = false;yhere = false;}
        }
        return false;
    }
};

// 主要还是写的思想重要，想到只要使用层次遍历，然后跟踪一下有关的值，自然就解决了问题

// 这个most vote答案，似乎没有我写的清楚，我是不是飘了~~~
bool isCousins(TreeNode* root, int x, int y) {
    queue<pair<TreeNode*, int>> q;
    q.emplace(root, 0);
    int parent = -1;
    
    while (!q.empty())
    {
        int size = q.size();
        for (int i=0;i<size;i++)
        {
            TreeNode* node = q.front().first;
            int value = q.front().second;
            
            if (node->val == x || node->val == y)
            {
                if (parent != -1)
                {
                    if (parent == value)
                        return false;
                    else
                        return true;
                }
                
                parent = value;
            }
            
            q.pop();
            if (node->left) q.emplace(node->left, node->val);
            if (node->right) q.emplace(node->right, node->val);
        }
        
        if (parent != -1)
        {
            return false;
        }
    }
    
    return false;
}

// recursive 答案， 应该来时间复杂度肯定大一点的~
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
		unordered_map<int, pair<int, int>> m;
		helper(root, 0, -1, m);
		return m[x].first == m[y].first && m[x].second != m[y].second;
    }
    void helper(TreeNode* node, int depth, int parent, unordered_map<int, pair<int, int>>& m) {
    	if (!node) return;
    	m[node->val] = {depth, parent};
    	helper(node->left, depth + 1, node->val, m);
    	helper(node->right, depth + 1, node->val, m);
    }
};
