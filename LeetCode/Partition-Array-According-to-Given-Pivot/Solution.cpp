1class Solution {
2public:
3    vector<int> pivotArray(vector<int>& nums, int pivot) {
4        vector<int> left;
5        vector<int> mid;
6        vector<int> right;
7        vector<int> result;
8        for(int i=0;i<nums.size();i++){
9            if(nums[i]==pivot) mid.push_back(nums[i]);
10            else if(nums[i]<pivot) left.push_back(nums[i]);
11            else right.push_back(nums[i]);
12        }
13        for(int i=0;i<left.size();i++) result.push_back(left[i]);
14        for(int i=0;i<mid.size();i++) result.push_back(mid[i]);
15        for(int i=0;i<right.size();i++) result.push_back(right[i]);
16
17        return result;
18    }
19};