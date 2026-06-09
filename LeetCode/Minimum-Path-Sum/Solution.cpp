1class Solution {
2public:
3    int f(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>> &dp){
4        if(i==m-1 && j==n-1) return grid[i][j];
5        if(i>=m || j>=n) return 1e9;
6        if(dp[i][j]!=-1) return dp[i][j];
7        int curr=grid[i][j];
8        int right= curr+f(i,j+1,m,n,grid,dp);
9        int down = curr+f(i+1,j,m,n,grid,dp);
10
11        return dp[i][j]=min(right,down); 
12    }
13    int minPathSum(vector<vector<int>>& grid) {
14        int m=grid.size();
15        int n=grid[0].size();
16        vector<vector<int>> dp(m,vector<int> (n,0));
17        //return f(0,0,m,n,grid,dp);
18        dp[m-1][n-1]=grid[m-1][n-1];
19        for(int i=m-1;i>=0;i--){
20            for(int j=n-1;j>=0;j--){
21                if(i==m-1 && j==n-1) continue;
22                else{
23                    int curr=grid[i][j];
24                    int right=1e9,down=1e9;
25                    if(j+1<=n-1) right= curr+dp[i][j+1];
26                    if(i+1<=m-1) down = curr+dp[i+1][j];
27                    dp[i][j] = min(right,down);
28                }
29            }
30        }
31        return dp[0][0];
32    }
33};