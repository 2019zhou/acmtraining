//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/532/week-5/3314/

// 打开lc, lc太高看我了，直接hard嘛，哭晕了~~~
// 我才刚刚觉得medium可以试一下，然后就hard了~
// 还是看题吧，或许是这几日荒废了，没有好好做题~~

// 发现没有那么难，，迷惑.jpg
// 细节情况还是需要好好考虑 
// 一个节点， 而且是负数
// 多个节点， 全部是负数

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
    int maxPathSum(TreeNode* root, int& ans){
        if(!root) return 0;
        int l = max(0, maxPathSum(root->left, ans));
        int r = max(0, maxPathSum(root->right, ans));
        int sum = l + r + root->val;
        ans = max(ans, sum);
        return max(l, r) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MIN;
        maxPathSum(root, ans);
        return ans;
    }
};

// 写了一个相当于帮助的函数
// ans相当于全局变量，只要有比ans更加大的值，就会更新
// 因为可能遇到负数 l r 中使用max来解决
// 注意到如果传到上一层节点的时候，能只能传一边，不能传两条边， 所以 return max(l,r) + root->val
// sum是包含当前节点的一个值

python解法，直接抄过来了
Solution 1: Helper returning two values: (240 ms, 8 lines)

def maxPathSum(self, root):
    def maxsums(node):
        if not node:
            return [-2**31] * 2
        left = maxsums(node.left)
        right = maxsums(node.right)
        return [node.val + max(left[0], right[0], 0),
                max(left + right + [node.val + left[0] + right[0]])]
    return max(maxsums(root))
My helper function returns two values:

The max sum of all paths ending in the given node (can be extended through the parent)
The max sum of all paths anywhere in tree rooted at the given node (can not be extended through the parent).
Solution 2: Helper updating a "global" maximum: (172 ms, 10 lines)

def maxPathSum(self, root):
    def maxend(node):
        if not node:
            return 0
        left = maxend(node.left)
        right = maxend(node.right)
        self.max = max(self.max, left + node.val + right)
        return max(node.val + max(left, right), 0)
    self.max = None
    maxend(root)
    return self.max
Here the helper is similar, but only returns the first of the two values (the max sum of all paths ending in the given node). Instead of returning the second value (the max sum of all paths anywhere in tree rooted at the given node), it updates a "global" maximum.
