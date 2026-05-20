1class Solution {
2public:
3    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
4        //build the graph
5        unordered_map<int,vector<pair<int,int>>> adj;
6        for(auto &e:times){
7            int u=e[0];
8            int v=e[1];
9            int wt=e[2];
10            adj[u].push_back({v,wt});
11        }
12
13        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
14        pq.push({0,k});
15        vector<int> result(n+1,INT_MAX);
16        result[k]=0;
17        while(!pq.empty()){
18            pair<int,int> p= pq.top();
19            int weight=p.first;
20            int int_node=p.second;
21            pq.pop();
22            if(weight>result[int_node]) continue;
23            for(auto &v:adj[int_node]){
24                int final_node=v.first;
25                int wt=v.second;
26
27                if(weight+wt< result[final_node]){
28                    result[final_node]=weight+wt;
29                    pq.push({result[final_node],final_node});
30                }
31            }
32        }
33        for(int i=1;i<=n;i++){
34            if(result[i]==INT_MAX) return -1;
35        }
36        int max=result[1];
37        for(int i=2;i<=n;i++){
38            if(result[i]>max) max=result[i];
39        }
40        return max;
41    }
42};