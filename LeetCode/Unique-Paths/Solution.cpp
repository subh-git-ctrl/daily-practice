1class Solution {
2public:
3    int f(int i,int j,int m,int n,vector<vector<int>> &dp){
4        
5        if(i==m-1 && j==n-1) return 1;
6        if(i>m-1 || j>n-1) return 0;
7
8        if(dp[i][j]!=-1) return dp[i][j];
9        int right=f(i,j+1,m,n,dp);
10        int down=f(i+1,j,m,n,dp);
11
12        return dp[i][j]=right+down;
13    }
14    int uniquePaths(int m, int n) {
15        vector<vector<int>> dp(m,vector<int> (n,-1));
16        return f(0,0,m,n,dp);
17    }
18};