1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4        unordered_map<int,int> mp; //key,freq
5        vector<int> v;
6        int n=nums.size();
7        for(int i:nums){
8            if(mp.count(i)) mp[i]++;
9            else mp.insert({i,mp[i]++});
10        }
11        int maxFreq=mp[nums[0]];
12        for(auto it:mp){
13            maxFreq=max(maxFreq,it.second);
14        }
15
16        //return mp[2] ;
17        //return maxFreq; this will return the max frequency not that particular element
18        int ans;
19        for(auto it:mp){
20            if(it.second==maxFreq) {
21                ans=it.first;
22                break;
23            }
24        }
25        return ans;
26    }
27    
28};