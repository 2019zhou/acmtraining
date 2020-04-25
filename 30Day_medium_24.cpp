//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3310/

// 猛然发现30day fail的忧伤~~~
// 典型的贪心题
// lc上貌似叫这个jump game的有8+

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int reach = 0; i<n && i <= reach;i++){
            reach = max(nums[i] + i, reach);
        }
        return i == n;
    }
};


// Difference between DP & Greedy Alg
// DP
// looking from the end each time and find the best possible way to reach the end
bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> jump(n,false);
        jump[n-1]=true;
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<=nums[i] && i+j<n;j++)
            {
                if(jump[i+j]==true) 
                {
                    jump[i]=true; 
                    break;
                }
            }
        }
        
        return jump[0];
    }
    
 // But greedy alg is like
 // Looking from the start and selecting the locally optimum in the hope of reaching global optimum
