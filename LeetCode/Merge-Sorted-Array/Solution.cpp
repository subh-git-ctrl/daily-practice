1class Solution {
2public:
3    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
4        
5        vector<int> v;
6        int n1=0;
7        int n2=0;
8        while(n1<m && n2<n){
9            if(nums1[n1]<=nums2[n2]) {
10                v.push_back(nums1[n1]);
11                n1++;
12            }
13            else {
14                v.push_back(nums2[n2]);
15                n2++;
16            }
17        }
18        if(n1==m) {
19            for(int i=n2;i<n;i++){
20                v.push_back(nums2[i]);
21            }
22        }
23        else if(n2==n) {
24            for(int i=n1;i<m;i++){
25                v.push_back(nums1[i]);
26            }
27        }
28
29        for(int i=0;i<m+n;i++){
30            nums1[i]=v[i];
31        }
32        
33    }
34};