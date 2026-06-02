1class Solution {
2public:
3    void ComSumIII(int i,vector<int> &arr,int target,int k,vector<int> &ds,vector<vector<int>> &result){
4        if(target==0){
5            if(ds.size()==k){
6                result.push_back(ds);
7            }
8            return ;
9        }
10        for(int j=i;j<9;j++){
11           // if(j>i && arr[j]==arr[j-1]) continue;
12            if(arr[j]<=target){
13                ds.push_back(arr[j]);
14                ComSumIII(j+1,arr,target-arr[j],k,ds,result);
15                ds.pop_back();
16            }
17        }
18
19    }
20    vector<vector<int>> combinationSum3(int k, int n) {
21        vector<int> arr = {1,2,3,4,5,6,7,8,9};
22        int target=n;
23        vector<int> ds;
24        vector<vector<int>> result;
25        ComSumIII(0,arr,target,k,ds,result);
26        int PSum[10];
27        PSum[0]=1;
28        for(int i=1;i<9;i++){
29            PSum[i]=PSum[i-1]+arr[i] ;
30        }
31        if(n<PSum[k-1]) return {};
32        return result;
33    }
34};