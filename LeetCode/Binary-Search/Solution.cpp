1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n=nums.size();
5        int low=0;
6        int high=n-1;
7
8        while(low<=high){
9            int mid= (low+high)/2;
10
11            if(target==nums[mid]) return mid;
12            else if(target<nums[mid]) high=mid-1;
13            else low=mid+1;
14        }
15        return -1;
16    }
17};