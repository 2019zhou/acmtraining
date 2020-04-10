//https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/631/

// 开始还觉得有点难，结果3分钟就过了，开心~~
// 就是一个简单的递归
// discussion里面说，这种使用vector stl库的方式不是非常的好，可以重写一个helper函数，然后再来传送，low, high, vector
// 这很科学！！！学习！！

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        int mid = nums.size()/2;
        TreeNode* head = new TreeNode(nums[mid]);
        vector<int> sleft = {nums.begin(), nums.begin() + mid};
        head->left = sortedArrayToBST(sleft);
        vector<int> sright = {nums.begin() + mid + 1, nums.end()};
        head->right = sortedArrayToBST(sright);
        return head;
    }
};


class Solution {
  public:
      TreeNode* sortedArrayToBST(vector<int>& nums) {
          return help(nums, 0, nums.size()-1);
      }

      TreeNode* help(vector<int> &nums, int start, int end){
          int _size=end-start;
          if(_size<0)    return NULL;
          if(_size==0)    return new TreeNode(nums[start]);
          int mid=(start+end)/2;
          TreeNode* root=new TreeNode(nums[mid]);
          root->left=help(nums, start, mid-1);
          root->right=help(nums, mid+1, end);
      }
  };
