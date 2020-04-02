//https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/572/
// Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int maxprofit = 0;
        int min = INT_MAX;
        for(int i = 0;i < prices.size();i++){
            if(prices[i] < min) min = prices[i];
            if(prices[i] - min > maxprofit) maxprofit = prices[i] - min;
        }
        return maxprofit;
    }
};

//注意，简单的寻找最小的那个，并且寻找最小的那个后面的最大的那个是不行的
// 应当从每一个点出发，
//          7 1 5 3 0 4
//min:      7 1 1 1 0 0
//maxprofit:0 0 4 2 0 4
// 看这个点左的最小的值，然后通过本点 - 左边最小的值 算出maxprofit
// 和存储的maxprofit进行比较，得出maxprofit
