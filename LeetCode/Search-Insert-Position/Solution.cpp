1class Solution {
2public:
3    int searchInsert(vector<int>& nums, int target) {
4        int n=nums.size();
5        int low=0;
6        int high=n-1;
7        int mid;
8        while(low<=high){
9            mid= (low+high)/2;
10            
11            if(target==nums[mid]) return mid;
12            else if(target<nums[mid]) high=mid-1;
13            else low=mid+1;
14        }
15
16        if(target>nums[mid])
17        return mid+1;
18        else return mid;
19    }
20};