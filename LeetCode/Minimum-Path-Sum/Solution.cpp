1class Solution {
2public:
3    int f(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>> &dp){
4        if(i==m-1 && j==n-1) return grid[i][j];
5        if(i>=m || j>=n) return 1e9;
6        if(dp[i][j]!=-1) return dp[i][j];
7        int right= grid[i][j]+f(i,j+1,m,n,grid,dp);
8        int down = grid[i][j]+f(i+1,j,m,n,grid,dp);
9
10        return dp[i][j]=min(right,down); 
11    }
12    int minPathSum(vector<vector<int>>& grid) {
13        int m=grid.size();
14        int n=grid[0].size();
15        vector<vector<int>> dp(m,vector<int> (n,-1));
16        return f(0,0,m,n,grid,dp);
17    }
18};