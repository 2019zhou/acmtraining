//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/880

class Solution {
public:
    int reverse(int x) {
        if(x == 0) return x;
        if(x == INT_MIN) return 0;
        int res = 0;
        int sign = x<0?-1 :1;
        x = x< 0 ? -x : x;
        while(x/10 > 0){
            if(res > INT_MAX/10) return 0;
            res = x%10 + res*10;
            x = x/10;
        }
        if(res > INT_MAX/10) return 0;
        res = x%10 + res*10;
        res = sign < 0? -res:res;
        return res;
    }
};

//非常繁琐，不简洁的解法了，但使用了很少的内存
//注意超出范围的表示方法 res > INT_MAX/10 因为平台如果int超限是报错，中止，不会溢出，所以预先判断减少INT_MAX/10
//wa 第一次是120 因为判断条件用的x%10 != 0 这样字如果数字中有0就可能会发生错误
//wa 第二次是 -2147483648 上面使用的是取绝对值，但是int中没有2147483648这个数，所以必须单独判断qaq
//ac了终于

//offical answer: calc like stack

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
