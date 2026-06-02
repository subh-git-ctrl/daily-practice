1class Solution {
2public:
3    void Perms(int i,vector<int>& nums,int n,vector<bool> &visited,vector<int> &ds,vector<vector<int>> &result){
4        if(ds.size()==n){
5            result.push_back(ds);
6            return ;
7        }
8
9        for(int ind=0;ind<n;ind++){
10            if(!visited[ind]){
11                visited[ind]=true;
12                ds.push_back(nums[ind]);
13                Perms(i,nums,n,visited,ds,result);
14                ds.pop_back();
15                visited[ind]=false;
16                //Perms(i,nums,n,visited,ds,result);
17            }
18        }
19    }
20    vector<vector<int>> permute(vector<int>& nums) {
21        int n=nums.size();
22        vector<bool> visited(n,false);
23        vector<int> ds;
24        vector<vector<int>> result;
25
26        Perms(0,nums,n,visited,ds,result);
27        return result;
28    }
29};