//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3305/discuss/589029/C++-Stack-Solution-O(n)

// 一道medium的题目，开始没有想明白的是无论是哪个节点都需要push到stack中一次，不然就会出问题
// 开始一直runtime error的原因是明明stack已经空了，自己还在里面继续stack.top()操作

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* head = new TreeNode(preorder[0]);
        stack<TreeNode*> pstack;
        pstack.push(head);
        TreeNode* temp;
        for(int i = 1;i < preorder.size();i++){
            temp = pstack.top();
            TreeNode* cur = new TreeNode(preorder[i]);
            if(temp->val > preorder[i]){
                temp->left = cur;
                pstack.push(cur);  
            } 
            else{
                while(!pstack.empty()){
                    temp = pstack.top();
                    pstack.pop();
                    if(pstack.empty()){temp->right = cur;break;}
                    else if(pstack.top()->val > preorder[i]){
                        temp->right = cur; 
                        break;
                    }     
                }
                pstack.push(cur);
             }
        }
        return head;
    }
};

// 康康其他dl的操作
// Concise & beautiful

int i = 0;
    TreeNode* bstFromPreorder(vector<int>& A, int bound = INT_MAX) {
        if (i == A.size() || A[i] > bound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = bstFromPreorder(A, root->val);
        root->right = bstFromPreorder(A, bound);
        return root;
    }
 
// python binary search这样子做出来的结果是O(nlogn)的复杂度
 def bstFromPreorder(self, A):
        def helper(i, j):
            if i == j: return None
            root = TreeNode(A[i])
            mid = bisect.bisect(A, A[i], i + 1, j)
            root.left = helper(i + 1, mid)
            root.right = helper(mid, j)
            return root
        return helper(0, len(A))
