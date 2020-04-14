//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3299/

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        string res;
        int direction;
        int amount;
        int sum = 0;
        for(int i = 0;i < shift.size();i++){
            direction = shift[i][0];
            amount = shift[i][1];
            if(direction == 0) sum -= amount; //0 represent left, sum is negative
            else sum += amount; // 1 represent right, sum is positive
        }
        if(sum > 0) sum = sum%(s.size());
        else {
            int temp = -sum;
            temp = temp%(s.size());
            sum = -temp;
        }
        if(sum < 0){
            res.append(s.begin()-sum,s.end());
            //cout << res << endl;
            res.append(s.begin(), s.begin()-sum);
            //cout << res << endl;
        }
        else{
            res.append(s.end()-sum, s.end());
            res.append(s.begin(), s.end()-sum);
        }
        return res;
    }
};

// 如此简单的题目居然会wa, wsl
// 但是既然wa了就要好好记录一下，history does not occur again.
// 感觉自己对于append什么的用法有点不确定，
// 还有就是size 求余数的时候，只有整数是余数啊，负数的话不要想着-号会帮你自动提取好不好，醉了自己
