1class Solution {
2public:
3    int ways(int n,vector<int> &dp){
4        if(n<=1) return dp[n]=1;
5        
6        if(dp[n]!=-1) return dp[n];
7        int left= ways(n-1,dp);
8        int right=ways(n-2,dp);
9        
10        return dp[n]=left+right;
11    }
12    int climbStairs(int n) {
13        vector<int> dp(n+1,-1);
14        return ways(n,dp);
15    }
16};