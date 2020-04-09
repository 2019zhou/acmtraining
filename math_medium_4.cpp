//https://leetcode.com/explore/interview/card/top-interview-questions-medium/113/math/818/

// 二分法来做函数pow(x, n)
class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MIN) {
            return myPow (1 / x, -(n + 1)) / x;
        }
        if (n < 0) {
            return myPow(1 / x, -n);
        }
    	double ans = 1;
		while (n) {
			if (n & 1 == 1) ans *= x;
			x *= x;
			n >>= 1;
		}
		return ans;
    }
};

// 如果x是偶数
// 2^8
// x  n
// 2  8
// 4  4
// 16 2
// 256 1
// 可以通过简单的运算 2^8 = (2^2)4 这样子验证这个算法是正确的

// 如果x是奇数
// 2^7
// x  n ans
// 2  7 2
// 4  3 8
// 16 1 8*16
// 显然这里还是少成了很多东西，需要维护一个另外的变量来补足 可以是ans 如果是奇数 就乘上x本身来补足
// 可以发现这里两者有了一个惊人的统一，只要是奇数，记录到ans中就可以了，答案就有了
	while (n) {
			if (n & 1 == 1) ans *= x;
			x *= x;
			n >>= 1;
		}
		return ans;
 }

//n 是负数转化成正数情况！！ 

// 注意还有一点极限情况n = INT_MIN 的时候, -n会轻轻松超出边界，所以还是单独判断，努力使他不超界吧。


// 开始还没用二分法的时候果断TLE了
