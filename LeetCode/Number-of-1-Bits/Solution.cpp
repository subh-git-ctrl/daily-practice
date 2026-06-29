1class Solution {
2public:
3    int hammingWeight(int n) {
4        int m=n;
5        int count=0;
6
7        while(m!=0){
8            int rem= m%2;
9            if(rem==1) count++;
10            m/=2;
11        }
12
13        return count;
14    }
15};