1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4        sort(nums.rbegin(),nums.rend());
5        return nums[k-1];
6    }
7};