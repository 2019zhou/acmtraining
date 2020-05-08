//https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/786/

// inorder traversal 中序遍历iterative 实现

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> stree;
        TreeNode* p = root;
        while(p!= NULL || !stree.empty()){
            while(p!= NULL){
                stree.push(p);
                p = p->left;
            }
            res.push_back(stree.top()->val);
            p = stree.top()->right;
            stree.pop();
        }
        return res;
    }
};

// 应该这个中序是比较简洁的了，注意光判断stree.emtpy()还不够，因为可能stree已经是空的但是p现在完全指向的是右子树，现在是对于右子树进行遍历

// Solution中还有一个Morris Traversal
/*
Step 1: Initialize current as root
Step 2: While current is not NULL,
If current does not have left child
    a. Add current’s value
    b. Go to the right, i.e., current = current.right
Else
    a. In current's left subtree, make current the right child of the rightmost node
    b. Go to this left child, i.e., current = current.left
*/

//Morris traversal
// 是一个不断的变换树的过程，直到这棵树变成一个全部都在右侧的单想树
// 时空复杂度还都是O(n), O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        while (root) {
            if (root -> left) {
                TreeNode* pre = root -> left;
                while (pre -> right && pre -> right != root) {
                    pre = pre -> right;
                }
                if (!pre -> right) {
                    pre -> right = root;
                    root = root -> left;
                } else {
                    pre -> right = NULL;
                    nodes.push_back(root -> val);
                    root = root -> right;
                }
            } else {
                nodes.push_back(root -> val);
                root = root -> right;
            }
        }
        return nodes;
    }
};
   
