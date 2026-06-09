1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, int k) {
4        sort(nums.begin(),nums.end());
5        int n=nums.size();
6        return (long long)k*(nums[n-1]-nums[0]);
7    }
8};