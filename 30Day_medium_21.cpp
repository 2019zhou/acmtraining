//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3306/

// 可二分
// 但也有优化算法


/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int m = binaryMatrix.dimensions()[0];
        int n = binaryMatrix.dimensions()[1];
        vector<int> res;
        
        for(int i = 0;i < m;i++){
            int lo = 0, hi = n, mid;
            while(lo < hi){
            mid = (lo + hi)/2;
            if(binaryMatrix.get(i, mid) == 0) lo = mid +1;
            else hi = mid;
            }
            res.push_back(lo);
        }
        int minres = INT_MAX;
        for(int i = 0;i < m;i++){
            if(res[i] < minres) minres= res[i];
            //cout << res[i] << ends;
        }
        return minres == n ? -1:minres;
    }
};

// 最近刷题越来越顺了，comeon!

// (Optimal Approach) Imagine there is a pointer p(x, y) starting from top right corner.
// p can only move left or down. If the value at p is 0, move down. 
// If the value at p is 1, move left. Try to figure out the correctness and time complexity of this algorithm.

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
	
		// Initialisations and matrix dimensions
        vector dims = binaryMatrix.dimensions();
        int rows = dims[0], cols = dims[1];
        int leftmostIndex = cols, index, left, right, mid, val, prevmid;
        
		// Find the first appearance of 1 in each row, and save its index if it is the leftmost index so far
        for (int i = 0; i < rows; ++i)
        {
            left = 0;
            right = leftmostIndex - 1;
			// To keep the last found 1, for cases in which the last checked value is 0
            prevmid = leftmostIndex;
            
			// Binary search algorithm, adapted to find the first appearance of the number 1
            while (left  mid)
                leftmostIndex = mid;
			// If the last checked value is 0 but a 1 has been found and it is the leftmost 1 so far, update the leftmost index accordingly
            if (!val && leftmostIndex > prevmid)
                leftmostIndex = prevmid;
        }
        
		// If a 1 has been found in the matrix, return the leftmost index. Otherwise, return -1.
        return leftmostIndex != cols ? leftmostIndex : -1;
		//return leftmostIndex > -1 && leftmostIndex != cols ? leftmostIndex : -1;
    }
};
