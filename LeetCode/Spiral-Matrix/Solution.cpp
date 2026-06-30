1class Solution {
2public:
3    vector<int> spiralOrder(vector<vector<int>>& matrix) {
4        int m=matrix.size();
5        int n=matrix[0].size();
6        // order is Right, D, L, U
7        vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
8        int index=0;
9        vector<int> ans;
10        vector<vector<bool>> visited(m, vector<bool> (n,false));
11        visited[0][0]= true;
12
13        ans.push_back(matrix[0][0]);
14        int row=0,col=0;
15        while(true){
16            if(ans.size()== m*n) break;
17            auto d= dir[index];
18            int row_new = row + d.first ;
19            int col_new = col + d.second ;
20
21            if(row_new>=0 && col_new>=0 && row_new<m && col_new<n && visited[row_new][col_new]==false) {
22                row= row_new;
23                col= col_new;
24                visited[row][col]=true;
25                ans.push_back(matrix[row][col]);
26            }
27
28            //else change the direction i.e the index
29            else index= (index+1) % 4 ; // did this so that after U we can go to right
30        }
31
32        return ans;
33    }
34};