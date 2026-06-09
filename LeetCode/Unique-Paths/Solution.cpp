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
16        //return f(0,0,m,n,dp); //memoization approach
17
18        //Tabulation
19        dp[m-1][n-1]=1;
20        for(int row=m-1;row>=0;row--){
21            for(int col=n-1;col>=0;col--){
22                if(row==m-1 && col==n-1) dp[row][col]=1;
23                else {
24                    int right=0, down=0;
25                    if(col+1<=n-1) right=f(row,col+1,m,n,dp);
26                    if(row+1<=m-1) down=f(row+1,col,m,n,dp);
27                    dp[row][col]=right+down;
28                }
29            }
30        }
31        return dp[0][0];
32
33    }
34};