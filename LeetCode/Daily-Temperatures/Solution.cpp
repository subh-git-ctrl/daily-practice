1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& temperatures) {
4        stack<pair<int,int>> st;
5        int len=temperatures.size();
6        vector<int> arr(len,0);
7        for(int i=len-1;i>=0;i--){
8            
9            if(st.empty()){ arr[i]=0; st.push({temperatures[i],i}); } else { while(!st.empty() && st.top().first<=temperatures[i]) st.pop(); if(st.empty()){ arr[i]=0; st.push({temperatures[i],i}); } else { arr[i]= st.top().second - i; st.push({temperatures[i],i}) ; } }
10            
11        }
12        return arr;
13    }
14};