1class Solution {
2public:
3    int minPathSum(vector<vector<int>>& grid) {
4        int m=grid.size();
5        int n=grid[0].size();
6        vector<int> prev(n);
7        //return f(0,0,m,n,grid,dp);
8        prev[n-1]=grid[m-1][n-1];
9        for(int i=m-1;i>=0;i--){
10            vector<int> curr(n,0);
11            for(int j=n-1;j>=0;j--){
12                if(i==m-1 && j==n-1) {
13                    curr[n-1]=grid[m-1][n-1];
14                    continue;
15                }
16                else{
17                    int curr_value=grid[i][j];
18                    int right=1e9,down=1e9;
19                    if(j+1<=n-1) right= curr_value+curr[j+1];
20                    if(i+1<=m-1) down = curr_value+prev[j];
21                    curr[j] = min(right,down);
22                }
23            }
24            prev=curr;
25        }
26        return prev[0];
27    }
28};