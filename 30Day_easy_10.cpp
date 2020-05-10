//Valid Perfect Square

// easy题啦
// 二分做法，注意这里用到了 leetcode 对于int的定义都是32位
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <= 0) return false;
        int lo = 0;
        int hi = max(num, 46340);
        while(lo <= hi){
            int mid = (hi - lo)/2 + lo;
            if(mid*mid == num) return true;
            if(mid*mid > num) hi = mid-1;
            else lo = mid+1;
        }
        return false;
    }
};

//Use Newton's method 
// 第一次听到这个名词，实际上说的就是 先猜测，然后通过切线不断逼近
long r = x;
    while (r*r > x)
        r = (r + x/r) / 2;
    return r*r == x;

// Newton Method的时间效率比二分好
