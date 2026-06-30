1class Solution {
2public:
3    void rotate(vector<vector<int>>& matrix) {
4        // 90 deg = transpose + reverse row
5        int n= matrix.size();
6
7        //Transpose it - N x N so no issues
8        for(int row=0;row<n;row++){
9            for(int col=row+1;col<n;col++){
10                swap(matrix[row][col],matrix[col][row]);
11            }
12        }
13        
14        for(int row=0;row<n;row++){
15            reverse(matrix[row].begin(),matrix[row].end());
16        }
17    }
18};