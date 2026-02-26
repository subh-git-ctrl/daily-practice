1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4        int length= 2* nums.size();
5        int len= nums.size();
6        stack<int> stk;
7        vector <int> arr(len,-1);
8        for(int i=length-1;i>=0;i--){
9            if(i<len){
10                while(!stk.empty() && stk.top()<= nums[i%len]) stk.pop();
11
12                if(stk.empty()) arr[i]=-1;
13                else arr[i]=stk.top();
14
15                stk.push(nums[i]);
16            }
17            else{
18                while(!stk.empty() && stk.top()<= nums[i%len]) stk.pop();
19
20                stk.push(nums[i%len]) ;
21            }
22        }
23        return arr;
24    }
25};