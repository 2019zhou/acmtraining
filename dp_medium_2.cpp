// https://leetcode-cn.com/contest/weekly-contest-257/problems/first-day-where-you-have-been-in-all-the-rooms/
// 智商不够用了
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<int> dp(n);
        for(int i = 1;i < n;i++){
            dp[i] = (2 * dp[i - 1] - dp[nextVisit[i - 1]] + 2) %mod;
            if(dp[i] < 0)
                dp[i] += mod;
        }
        return dp[n - 1];
    }
};
