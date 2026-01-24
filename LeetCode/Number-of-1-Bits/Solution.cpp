1class Solution {
2public:
3    int hammingWeight(int n) {
4        int m=n;
5        int count=0;
6        while(m!=0){
7            int rem=m%2;
8            if(rem==1) count++;
9            m/=2;
10        }
11        return count;
12    }
13};