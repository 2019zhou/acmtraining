// part of the leetcode 30 day challenge, day2
// ac first time

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> mp;
        int sum = 0;
        while(true){
            sum = 0;
            while(n != 0){
                sum += (n%10) * (n%10);
                n = n/10;
                //cout << n << ends << sum << endl;
            }
            //cout << "Final sum:" << sum << endl;
            if(sum == 1) return true;
            else if(mp[sum]>=1) return false;
            else mp[sum]++;
            n = sum;
        }
    }
};
//使用了unordered_map就解决了问题
