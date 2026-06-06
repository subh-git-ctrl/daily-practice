1class Solution {
2public:
3    int max_money(int i, vector<int>& nums, vector<int> &dp){
4        if(i==0) return dp[i]=nums[i];
5        if(i<0) return 0;
6        if(dp[i]!=-1) return dp[i];
7        int pick= nums[i]+ max_money(i-2,nums,dp);
8        int not_pick = 0 + max_money(i-1,nums,dp);
9
10        return dp[i]=max(pick,not_pick);
11    }
12    int rob(vector<int>& nums) {
13        int n=nums.size();
14        vector<int> dp(n,-1);
15        return max_money(n-1,nums,dp);
16    }
17};