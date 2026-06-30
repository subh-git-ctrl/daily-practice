1class Solution {
2public:
3    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
4        int r=matrix.size();
5        int c=matrix[0].size();
6        vector<vector<int>> new_matrix(c, vector<int> (r,-1));
7        for(int col=0;col<c;col++){
8            for(int row=0;row<r;row++){
9                new_matrix[col][row] = matrix[row][col];
10            }
11        }
12        return new_matrix;
13    }
14};