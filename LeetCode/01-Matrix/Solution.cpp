1class Solution {
2public:
3    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
4        //multi source bfs from all zeroes
5        int m=mat.size();
6        int n=mat[0].size();
7        queue<pair<int,int>> qu;
8        vector<vector<int>> directions={{-1,0},{1,0},{0,1},{0,-1}};
9        vector<vector<int>> result(m,vector<int> (n,-1));
10        for(int i=0;i<m;i++){
11            for(int j=0;j<n;j++){
12                if(mat[i][j]==0){
13                    result[i][j]=0;
14                    qu.push({i,j});
15                }
16            }
17        }
18
19        while(!qu.empty()){
20            int size=qu.size();
21            while(size--){
22                auto P=qu.front();
23                qu.pop();
24                int i=P.first;
25                int j=P.second;
26
27                for(auto &dir:directions){
28                    int i_new=i+dir[0];
29                    int j_new=j+dir[1];
30
31                    if(i_new>=0 && i_new<m && j_new>=0 && j_new<n && result[i_new][j_new]==-1){
32                        result[i_new][j_new]=result[i][j]+1;
33                        qu.push({i_new,j_new});
34                    }
35                }
36
37            }
38        }
39        return result;
40    }
41};