1class Solution {
2public:
3    bool binarySearch(vector<int>& v,int target){
4        int low= 0;
5        int high= v.size()-1;
6        int mid;
7
8        while(low<=high){
9            mid= low +(high-low)/2 ;
10
11            if(v[mid]==target) return true;
12            else if(v[mid]>target) high=mid-1;
13            else low=mid+1;
14        }
15        return false;
16    }
17    bool searchMatrix(vector<vector<int>>& matrix, int target) {
18        for(int i=0;i<matrix.size();i++){
19            //vector<int> v=matrix[i];
20            bool b= binarySearch (matrix[i],target);
21            if(b) return true;
22        }
23        return false;
24    }
25};