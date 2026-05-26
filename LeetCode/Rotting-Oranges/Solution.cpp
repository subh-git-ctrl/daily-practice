1class Solution {
2public:
3    int multi_source_bfs(int &m,int &n,queue<pair<int,int>> &qu,vector<vector<int>> &grid,vector<pair<int,int>> &directions,int &fresh){
4        int minutes=0;
5        while(!qu.empty() && fresh>0){
6            int size=qu.size();
7            while(size--){
8                auto u=qu.front();
9                qu.pop();
10                int i=u.first;
11                int j=u.second;
12                grid[i][j]=2;
13                for(auto &dir:directions){
14                    int i_new=i+ dir.first;
15                    int j_new=j+ dir.second;
16
17                    if(i_new>=0 && i_new<m && j_new>=0 && j_new<n && grid[i_new][j_new]==1){
18                        grid[i_new][j_new]=2;
19                        qu.push({i_new,j_new});
20                        fresh--;
21                    }
22                }
23            }
24            minutes++;
25        }
26        return minutes;
27    }
28    int orangesRotting(vector<vector<int>>& grid) {
29        int m=grid.size();
30        int n=grid[0].size();
31        vector<pair<int,int>> directions={{-1,0},{1,0},{0,1},{0,-1}};
32        queue<pair<int,int>> qu;
33        int fresh=0;
34        for(int i=0;i<m;i++){
35            for(int j=0;j<n;j++){
36                if(grid[i][j]==2){
37                    qu.push({i,j});
38                }
39                else if(grid[i][j]==1)//fresh oranges
40                    fresh++;
41            }
42        }
43        
44        int minutes=multi_source_bfs(m,n,qu,grid,directions,fresh);
45        if(fresh!=0) return -1;
46        return minutes;
47    }
48};