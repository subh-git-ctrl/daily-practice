1class Solution {
2public:
3    void subset(vector<int>& nums,vector<int>& ans,set<vector<int>> &st,int i,int n){
4        if(i==n) {
5            st.insert(ans);
6            return ;
7        }
8        ans.push_back(nums[i]);
9        subset(nums,ans,st,i+1,n);
10        ans.pop_back();
11        subset(nums,ans,st,i+1,n);
12    }
13    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
14        sort(nums.begin(),nums.end());
15        set<vector<int>> st;
16        int n=nums.size();
17        vector<int> ans;
18        subset(nums,ans,st,0,n);
19        vector<vector<int>> final;
20        for(auto &vec:st){
21            final.push_back(vec);
22        }
23        return final;
24    }
25};