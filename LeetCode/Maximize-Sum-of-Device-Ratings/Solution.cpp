1class Solution {
2public:
3    long long maxRatings(vector<vector<int>>& units) {
4        int m = units.size();
5        int n = units[0].size();
6        long long n_1_sum=0;
7        if(n==1){
8            for(int i=0;i<m;i++) n_1_sum+=units[i][0];
9            return n_1_sum;
10        }
11        
12        int global_min = INT_MAX;
13        long long sum_secmaxi = 0;
14        int sec_maxi_min = INT_MAX;
15        for (auto& row : units) {
16            sort(row.begin(), row.end());
17
18            global_min = min(global_min, row[0]);
19            sec_maxi_min = min(sec_maxi_min, row[1]);
20            sum_secmaxi += row[1];
21        }
22        return sum_secmaxi-sec_maxi_min+global_min ;
23    }
24};