1class Solution {
2public:
3    int minElement(vector<int>& nums) {
4        int n=nums.size();
5        int mini=INT_MAX;
6        for(auto &it:nums){
7            int sum=0;
8            while(it!=0){
9                int rem=it%10;
10                sum+=rem;
11                it/=10;
12            }
13            mini=min(mini,sum);
14        }
15        return mini;
16    }
17};