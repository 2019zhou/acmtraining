//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3312/

// 还是dp题目
// 非常经典

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int sz = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0; j < n;j++){
                if(!i || !j || matrix[i][j] == '0'){
                    dp[i][j] = matrix[i][j] - '0';
                }else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
                sz = max(dp[i][j], sz);
            }
        }
        return sz* sz;
    }
};

// 由于每一次只是用到了dp[i-1][j-1], dp[i-1][j], dp[i][j-1], 所以空间的角度可以优化
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<int> pre(n, 0), cur(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j || matrix[i][j] == '0') {
                    cur[j] = matrix[i][j] - '0';
                } else {
                    cur[j] = min(pre[j - 1], min(pre[j], cur[j - 1])) + 1;
                }
                sz = max(cur[j], sz);
            }
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
        }
        return sz * sz;
    }
};

// 下面是开始的想法，很不对~~
// 这个解法有点暴力
// 也就是如果遇到是0， 把行列都标记为已经不行了
// 对于数组再重新计算最长的子序列的长度，取一下max
