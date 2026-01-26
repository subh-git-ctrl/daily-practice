1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        int m=matrix.size();
5        int n=matrix[0].size();
6        int row=0;
7        int col=n-1;
8        
9        while(row<m && col>=0){
10            if(matrix[row][col]==target) return true;
11            else if(matrix[row][col]>target) col--;
12            else row++;
13        }
14        return false;
15    }
16};