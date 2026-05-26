1class Solution {
2public:
3    //bfs for finding the farthest node
4    int bfs_traversal_farthest(int u,unordered_map<int,vector<int>> &adj,vector<int> &visited){
5        queue<int> qu;
6        visited[u]=true;
7        qu.push(u);
8        int farthest_node=u;
9        while(!qu.empty()){
10            int size=qu.size();
11            while(size--){
12                int u=qu.front();
13                qu.pop();
14                for(auto &v:adj[u]){
15                    if(visited[v]==false){
16                        visited[v]=true;
17                        farthest_node=v;
18                        qu.push(v);
19                    }
20                }
21            }
22            
23            
24        }
25        return farthest_node;
26    }
27
28    //bfs for returning the number of levels(diameter+1)
29    int bfs_traversal_levels(int u,unordered_map<int,vector<int>> &adj,vector<int> &visited){
30        queue<int> qu;
31        visited[u]=true;
32        qu.push(u);
33        int levels=0;;
34        while(!qu.empty()){
35            int size=qu.size();
36            while(size--){
37                int u=qu.front();
38                qu.pop();
39                for(auto &v:adj[u]){
40                    if(visited[v]==false){
41                        visited[v]=true;
42                        qu.push(v);
43                    }
44                }
45            }
46            levels++;
47        }
48        return levels;
49    }
50    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
51        //Find the diameter of both the trees, then find ceil(dia/2) of both, then add and also add an extra 1 coz of the new edge between the trees.
52        if(edges1.size()==0 && edges2.size()==0) return 1;
53        //for a tree, n nodes have n-1 edges, we are given edges so we get the number of nodes
54        int V1=edges1.size()+1;
55        int V2=edges2.size()+1;
56        unordered_map<int,vector<int>> adj1;
57        
58        unordered_map<int,vector<int>> adj2;
59        
60
61        for(auto &e1:edges1){
62            int u=e1[0];
63            int v=e1[1];
64            adj1[u].push_back(v);
65            adj1[v].push_back(u);
66        }
67         for(auto &e2:edges2){
68            int u=e2[0];
69            int v=e2[1];
70            adj2[u].push_back(v);
71            adj2[v].push_back(u);
72        }
73
74        //Finding diameter of tree 1
75        //int V1=adj1.size(); we domnt do this coz edges cases me dikkt when one of the trees is empty
76        vector<int> visited1(V1,false);
77        int tree1_A= bfs_traversal_farthest(0,adj1,visited1);
78        visited1= vector<int> (V1,false);
79        int level1= bfs_traversal_levels(tree1_A,adj1,visited1);
80        int dia1= level1-1;
81
82        //Finding diameter of tree 1
83        //int V2=adj2.size();
84        vector<int> visited2(V2,false);
85        int tree2_A= bfs_traversal_farthest(0,adj2,visited2);
86        visited2= vector<int> (V2,false);
87        int level2= bfs_traversal_levels(tree2_A,adj2,visited2);
88        int dia2= level2-1;
89
90        //min dia= ceil(dia1/2)+ceil(dia2/2)+1
91        int min_dia= ceil((double)dia1/2)+ceil((double)dia2/2)+1 ;
92        return max({dia1,dia2,min_dia});
93        //dia1 = 10 dia2 = 1, min_dia=7, we cant return 7 coz it isnt max, so we return dia1 in this case
94
95        
96        
97    }
98};