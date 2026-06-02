1class Solution {
2public:
3    void ComSum(int index, vector<int>& candidates, int n, int target,
4                vector<int>& ds, vector<vector<int>>& result) {
5        if (index == n) {
6            if (target == 0) {
7                result.push_back(ds);
8                return;
9            }
10            return ;
11        }
12        if (candidates[index] <= target) {
13            ds.push_back(candidates[index]);
14            ComSum(index, candidates, n, target - candidates[index], ds, result);
15            ds.pop_back();
16        }
17
18        ComSum(index + 1, candidates, n, target, ds, result);
19    }
20    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
21        int n = candidates.size();
22        vector<int> ds;
23        vector<vector<int>> result;
24        ComSum(0, candidates, n, target, ds, result);
25        return result;
26    }
27};