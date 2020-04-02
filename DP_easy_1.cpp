//https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/569/
// 动规中最经典的爬楼梯问题。
//brute force

class Solution {
public:
    int climbStairs(int n) {
         return climbStairs(0,n);
    }
    int climbStairs(int i, int n){
      if(i > n) return 0;
      if(i == n) return 1;
      return climbStairs(i + 1, n) + climbStairs(i + 2, n);
    }
};

//recursion with memorizataion
class Solution {
public:
    int climbStairs(int n) {
        int *memo = new int[n];
        return climbStairs(0,n,memo);
    }
    int climbStairs(int i, int n, int* memo){
        if(i > n) return 0;
        if(i == n) return 1;
        if(memo[i] > 0) return memo[i];
        memo[i] = climbStairs(i + 1, n, memo) + climbStairs(i + 2, n, memo);
        return memo[i];
    }
};

// 一点只能使用指针 int* memo, 如果是int memo[n] = 就不可以
// 在C++ 中 memo[n] 是分配在stack上的，而int* memo是分配在堆heap上面的， 后者更加的dynamic, that is dynamic heap & static stack

//DP solution

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        int* memo = new int[n+1];
        memo[1] = 1;
        memo[2] = 2;
        for(int i = 3;i <=n;i++){
            memo[i] = memo[i - 1] + memo[i -2];
        }
        return memo[n];
    }
};


// 因为走到i个只可能有i-1走一步和i-2走两步
// 所以3只可能是第一个和第二个的情况的相加，（递归->递推）
// 可以发现就是一个斐波那契数列，dp nb!
