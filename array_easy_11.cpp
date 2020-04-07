//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/770/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    /*
    clock reverse: reverse[j][n-1-i] = a[i][j]
    */
        reverse(matrix.begin(), matrix.end());   /** a[n-1-i][j]=a[i][j] **/
        for(int i=0; i<matrix.size(); i++){   /** a[i][j]=a[j][i] **/
            for(int j=i+1; j<matrix[i].size(); j++)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};


// 感觉这个关键是数学的旋转的那个式子要知道。。。
// clock reverse 的这个解法非常优雅而简洁了
