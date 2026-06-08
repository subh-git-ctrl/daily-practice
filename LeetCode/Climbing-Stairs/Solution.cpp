1class Solution {
2public:
3    int climbStairs(int n) {
4        vector<int> dp(n+1,-1);
5        dp[n]=1;
6        for(int i=n-1;i>=0;i--){
7            int left =0,right=0;
8
9            left=dp[i+1];
10            if(i+2<=n) right=dp[i+2];
11            dp[i]=left+right;
12        }
13        return dp[0];
14    }
15};