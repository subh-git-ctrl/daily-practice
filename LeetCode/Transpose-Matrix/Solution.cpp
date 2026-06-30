1class Solution {
2public:
3    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
4        int r=matrix.size();
5        int c=matrix[0].size();
6        vector<vector<int>> new_matrix(c, vector<int> (r,-1));
7        for(int i=0;i<r;i++){
8            for(int j=0;j<c;j++){
9                new_matrix[j][i] = matrix[i][j];
10            }
11        }
12        return new_matrix;
13    }
14};