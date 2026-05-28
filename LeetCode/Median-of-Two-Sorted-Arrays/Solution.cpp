1class Solution {
2public:
3    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
4        int m=nums1.size();
5        int n=nums2.size();
6
7        int i=0;
8        int j=0;
9
10        vector<int> v;
11        while(i<m && j<n){
12            if(nums1[i]<nums2[j]){
13                v.push_back(nums1[i]);
14                i++;
15            }
16            else{
17                v.push_back(nums2[j]);
18                j++;
19            }
20        }
21
22        while(i<m){
23            v.push_back(nums1[i++]);
24        }
25        while(j<n){
26            v.push_back(nums2[j++]);
27        }
28        int mid= (m+n)/2 ;
29        if((m+n) % 2==0) {
30            double median= (double)( v[mid-1] + v[mid] )/2 ;
31            return median;
32        }
33        else {
34            double median= v[mid] ;
35            return median;
36        }
37    }
38};