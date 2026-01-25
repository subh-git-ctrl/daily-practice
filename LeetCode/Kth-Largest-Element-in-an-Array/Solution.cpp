1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4        priority_queue<int,vector<int>,greater<int>> pq;
5
6        for(int num:nums){
7            pq.push(num);
8            if(pq.size()>k) pq.pop();
9        }
10        return pq.top();
11    }
12};