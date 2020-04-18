//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3303/

// 典型的dp题目
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int sz = grid.size();
        if(sz == 0) return 0;
        int n = grid[0].size();
        // classic dp
        vector<vector<int>> dp(sz, vector<int>(n, -1));
        // fill the first row
        dp[0][0] = grid[0][0];
        for(int i = 1;i < n;i++)  dp[0][i] = dp[0][i-1] + grid[0][i]; 
        // fill the first column
        for(int j = 1;j < sz;j++) dp[j][0] = dp[j-1][0] + grid[j][0];
        // fill the whole table
        for(int i = 1;i < sz;i++){
            for(int j = 1;j < grid[0].size();j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[sz -1][n-1];
    }
};
//我的解决方案是完全没有优化的dp

// 对于空间的优化，因为写dp的时候实际上只要用到两行，空间可以只保留两行
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> pre(m, grid[0][0]);
        vector<int> cur(m, 0);
        for (int i = 1; i < m; i++)
            pre[i] = pre[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++) { 
            cur[0] = pre[0] + grid[0][j]; 
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], pre[i]) + grid[i][j];
            swap(pre, cur); 
        }
        return pre[m - 1];
    }
};

// Further inspecting the above code, 
// it can be seen that maintaining pre is for recovering pre[i],
// which is simply cur[i] before its update. So it is enough to use only one vector. Now the space is further optimized and the code also gets shorter.

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cur(m, grid[0][0]);
        for (int i = 1; i < m; i++)
            cur[i] = cur[i - 1] + grid[i][0]; 
        for (int j = 1; j < n; j++) {
            cur[0] += grid[0][j]; 
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
        }
        return cur[m - 1];
    }
};

// 到此空间优化到了O(n),即只要保留一行就可以
