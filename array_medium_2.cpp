//https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/777/


// 要求是in-place, 基本上自己的算法达到了空间最优， 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
        int m = matrix.size();
        int n = matrix[0].size();
        bool x = false;
        bool y = false;
        for(int i = 0;i < m ;i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                    if(i == 0) x = true;
                    if(j == 0) y = true;
                }  
            }
        }
        
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(x == true){
            for(int i = 0;i < n;i++){
                matrix[0][i] = 0;
            }
        } 
        if(y == true){
            for(int i = 0;i < m;i++)
                matrix[i][0] = 0;
        }
    }
};

// Comeon!
