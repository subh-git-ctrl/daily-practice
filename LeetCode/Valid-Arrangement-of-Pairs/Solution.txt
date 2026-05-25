1class Solution {
2public:
3    void dfs_traversal(int u,unordered_map<int, vector<int>> &adj,stack<int> &st){
4        while(!adj[u].empty()){
5            int v=adj[u].back();
6            adj[u].pop_back();
7            dfs_traversal(v,adj,st);
8        }
9        st.push(u);//top element is source
10    }
11    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
12        int size=pairs.size();
13        unordered_map<int, pair<int,int>> ver;//pair {indeg,outdeg}
14        unordered_map<int, vector<int>> adj;//build the graph
15        for(auto &p:pairs){
16            int u=p[0];//out
17            int v=p[1];//in
18            ver[u].second++;
19            ver[v].first++;
20            adj[u].push_back(v);
21
22        }
23        int V=adj.size();
24        int src,dest;//finding source and destination
25        int count=0;// lmao this wont work coz the order of pairs may be different, check the test case. so we need to follow the same dfs thing and we need to make source as pairs[0][0] .if count==number of vertices, that means that all the vertices have 1 indeg, 1 outdeg so its basically an euler circuit so we can just return the given pairs as for a eulerian circuit, the source can be any of the nodes,
26        //we keep the source as pairs[0]0, so if there is euler ckt, it wont get updated below
27        src=pairs[0][0];
28        for(auto &map:ver){
29            int node=map.first;
30            auto deg=map.second;
31            int indeg=deg.first;
32            int outdeg=deg.second;
33            if((outdeg-indeg)==1) {
34                src=node;
35                
36            }
37            else if((outdeg-indeg)==-1) dest=node;
38            else count++;
39        }
40
41        //if(count==V) return pairs;//does nt work
42    
43        //we only need source tho, we dont need dest here
44        //now we can just call dfs right
45        stack<int> st;
46        
47        dfs_traversal(src,adj,st);
48        vector<int> ans;
49        while(!st.empty()){
50            int node=st.top();
51            ans.push_back(node);
52            st.pop();
53        }
54        //reverse(ans.begin(),ans.end()); 
55        int ans_size=ans.size();
56        vector<vector<int>> result;
57        for(int i=0;i<ans_size-1;i++){
58            result.push_back({ans[i],ans[i+1]});
59        }
60        return result;
61        
62        
63        
64
65    }
66};