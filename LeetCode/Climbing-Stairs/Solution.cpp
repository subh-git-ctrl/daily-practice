1class Solution {
2public:
3    int f(int i,int n,vector<int> &dp){
4        if(i==n) return 1;
5        if(i>n) return 0;
6        if(dp[i]!=-1) return dp[i];
7        int left=f(i+1,n,dp);
8        int right=f(i+2,n,dp);
9        return dp[i]=left+right;
10    }
11    int climbStairs(int n) {
12        vector<int> dp(n+1,-1);
13        return f(0,n,dp);
14    }
15};