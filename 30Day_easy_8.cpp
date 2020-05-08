// 求一些点是不是都在一条直线上的

// 典型的easy题目，但是使用乘法而不是除法的思想还是值得借鉴的~~

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n <= 2) return true;
        int deltax = coordinates[1][0]-coordinates[0][0];
        int deltay = coordinates[1][1]-coordinates[0][1];
        int y0 = coordinates[1][1];
        int x0 = coordinates[1][0];
        for(int i = 2;i < n;i++){
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            if(deltax*(y - y0) != deltay*(x - x0))
                return false;
        }
        return true;
    }
};
