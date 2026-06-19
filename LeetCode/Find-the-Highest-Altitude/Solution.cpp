1class Solution {
2public:
3    int largestAltitude(vector<int>& gain) {
4        int n=gain.size();
5        int prev=0;
6        int maxi=0;
7        for(int i=0;i<n;i++){
8            maxi= max(maxi, prev+gain[i]);
9            prev+=gain[i];
10        }
11        return maxi;
12    }
13};