1class Solution {
2public:
3    using ll=long long;
4    long long maxTotalValue(vector<int>& nums, int k) {
5        int n=nums.size();
6        ll maxi=INT_MIN;
7        ll mini=INT_MAX;
8        for(int i=0;i<n;i++){
9            maxi=max(maxi,(ll)nums[i]);
10            mini=min(mini,(ll)nums[i]);
11        }
12
13        return (ll)k*(maxi-mini);
14    }
15};