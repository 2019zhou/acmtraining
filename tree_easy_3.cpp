//https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/627/
//fool brute force & much memory use method yet ac
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
    bool isSymmetric(TreeNode* root) {
        int t = maxDepth(root);
        vector<TreeNode*> temp;
        temp.push_back(root);
        TreeNode* p;
        int i = 0;
        while(temp.size() < pow(2,t) - 2){
            p = temp[i];
            i++;
            if(p!= NULL){
            temp.push_back(p->left);
            temp.push_back(p->right);
            }
            else{
            temp.push_back(NULL);
            temp.push_back(NULL);
            }
        }
        int k;
        for(int i = 1;i < t;i++){
            k = pow(2,i+1)-2;
            for(int j = pow(2,i)-1;j<k;j++,k--){
                //cout << j << ends << k << endl;
                if(temp[j] && temp[k] && temp[j]->val != temp[k]->val){
                    //cout << temp[j]->val << ends << temp[k]->val << endl;
                    return false;
                }
                if(temp[j] && !temp[k]) return false;
                if(temp[k] && !temp[j]) return false;
                //if(temp[j] && temp[k])cout << temp[j]->val << ends << temp[k]->val << endl;
            }
        }
        return true;
    }
    
    int maxDepth(TreeNode *root){
    return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
};
//这个思想非常暴力，就是全部放在一个队列中，没有任何节省空间的做法，没有节点的地方都是null
//用maxDepth来算出所要的全部大小，并控制
//然后

// smart & few memory few & fast method in the discussion 
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        TreeNode* left, *right;

        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()){
            left = q1.front();
            right = q2.front();
            q1.pop();
            q2.pop();
            if(left == NULL && right == NULL)continue;
            if(left == NULL || right == NULL)return false;
            if(left->val != right->val) return false;
            //cout << left->val << ends << right->val << endl;
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};

//注意几点
//1. 71行的TreeNode* left,*right; *在前，在后没有什么大的关系，但是重要的是一定要加*
//2. 先判断强条件，后判断弱条件
//if(left == NULL && right == NULL)continue;
//if(left == NULL || right == NULL)return false;
//这两句如果调换位置会导致出错
