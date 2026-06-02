1class Solution {
2public:
3    void Perms(vector<int>& nums,int index,int n,vector<vector<int>> &result ){
4        if(index==n){
5            result.push_back(nums);
6            return ;
7        }
8
9        for(int i=index;i<n;i++){
10            swap(nums[index],nums[i]);
11            Perms(nums,index+1,n,result);
12            swap(nums[index],nums[i]);
13        }
14    }
15    vector<vector<int>> permute(vector<int>& nums) {
16        vector<int> ans;
17        vector<vector<int>> result;
18        int n=nums.size();
19        Perms(nums,0,n,result);
20        return result;
21    }
22};