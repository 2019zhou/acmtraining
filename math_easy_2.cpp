//https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/744/

class Solution {
public:
    int countPrimes(int n) {
        int* num = new int[n];
        int j;
        for(int i = 2;i <= sqrt(n);){
            j = i;
            while(i * j < n){
                num[i*j] = -1;
                j++;
            }
            i++;
            while(num[i] == -1) i++;
        }
        int sum = 0;
        for(int i = 2;i < n;i++){
            if(num[i] != -1) sum++;
        }
        return sum;
    }
};

// 构造一个筛子，把不是质数的筛除，这还可以优化改成bool数组
