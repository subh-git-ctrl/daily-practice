1class Solution {
2public:
3    int missingNumber(vector<int>& nums) {
4        int sum=0;
5        int n=nums.size();
6        for(int i=0;i<n;i++){
7            sum+=nums[i];
8        }
9
10        return (n*(n+1)/2) - sum ;
11
12    }
13};