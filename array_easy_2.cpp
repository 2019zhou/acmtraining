//for 用的太多，现在都开始不喜欢写i++了。。。
//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/564/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sum = 0;
        int i = 1;
        while(i < n){
            if(prices[i - 1] < prices[i]) sum += prices[i] - prices[i - 1];
            i++;
        }
        return sum;
    }
};

//之前python版本的判断小范围数据可以不要
