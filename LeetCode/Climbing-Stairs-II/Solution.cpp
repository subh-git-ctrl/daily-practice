1class Solution {
2public:
3    long long f(int i,int n,vector<int>& costs,vector<long long> &dp){
4        if(i==n) return 0;
5        if(i>n) return 1e7;
6
7            if(dp[i+1]!=-1) return dp[i+1];
8        
9        long long first=1e8,second=1e8,third=1e8;
10        if(i+1<=n) first=costs[i+1]+1+f(i+1,n,costs,dp);
11        if(i+2<=n) second=costs[i+2]+4+f(i+2,n,costs,dp);
12        if(i+3<=n)third=costs[i+3]+9+f(i+3,n,costs,dp);
13
14        return dp[i+1]=min(first, min(second,third));
15
16
17    }
18    int climbStairs(int n, vector<int>& costs) {
19        vector<long long> dp(n+1,-1);
20        return f(-1,n-1,costs,dp);
21    }
22};