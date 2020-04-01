//https://leetcode.com/explore/interview/card/top-interview-questions-easy/96/sorting-and-searching/774/
//开始的时候妄想用linear search 把这题brute force解决，看来还是太傻。。 果断TLE
// 再921239930  823161944这个测试样例上fail了
// 当时想的version前面好的多，只有几个，后面坏的比例不算多，结果，，test case 数字有点大。。。

// 题解solution也是非常的好玩
//If you fall into this subtle overflow bug, you are not alone.
//Even Jon Bentley's own implementation of binary search had this overflow bug and remained undetected for over twenty years.
// Aha I'm  not afraid of the overflow bug, but it is annoying

//TLE version
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        for(int j = n;j >= 2;j--){
            if(isBadVersion(j) && !isBadVersion(j - 1)) return j;
        }
        return 1;
    }
};

// mid的设置 mid = (left - right) /2 + left; 而不是(left + right) /2;
// 因为后者可能会使得他overflow, 如果使用python除外！

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int mid;
        while(low < high){
            mid = (high - low)/2 + low; 
            if(isBadVersion(mid)) high = mid;
            else low = mid+1;
        }
        return low;
    }
};

//binary search的熟练掌握

