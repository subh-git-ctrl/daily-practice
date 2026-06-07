1class Solution {
2public:
3    vector<int> leftRightDifference(vector<int>& nums) {
4        int n=nums.size();
5        vector<int> leftSum(n);
6        vector<int> rightSum(n);
7        vector<int> ans(n);
8
9        for(int i=1;i<n;i++){
10            leftSum[i]=leftSum[i-1]+nums[i-1];
11            rightSum[n-i-1]=rightSum[n-i]+nums[n-i];
12        }
13        for(int i=0;i<n;i++){
14            ans[i]=abs(leftSum[i]-rightSum[i]);
15        }
16        return ans;
17    }
18};