//https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/601/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pt;
        if(numRows == 0) return pt;
        vector<int> temp1;
        temp1.push_back(1);
        pt.push_back(temp1);
        if(numRows == 1) return pt;
        for(int i = 1;i < numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j = 1;j < i;j++){
                temp.push_back(pt[i-1][j-1] + pt[i-1][j]);
            }
            temp.push_back(1);
            pt.push_back(temp);
        }
        return pt;
    }
};

// 开始j < i 写错了莫名其妙

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(auto i=0;i<numRows;++i)
        {
            res.push_back(vector<int>(i+1,1));
            for(auto j=1; j<i; ++j) res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
        return res;
    }
};

// 这样写，更加暴力，简洁

// 这题其实也相当于一道动态规划，因为也是利用了前面的子问题的解来形成后面问题的解
