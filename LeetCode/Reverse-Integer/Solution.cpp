1class Solution {
2public:
3    long long rev(long long n){
4        long long m=n;
5        long long sum=0;
6        while(m!=0){
7            int rem=m%10;
8            sum=sum*10+rem;
9            m/=10;
10        }
11        return sum;
12    }
13    int reverse(int m) {
14        long long x=m;
15        long long ans;
16        if(x<0){
17            long long y=-x;
18            
19            ans=-rev(y);
20        }
21        else ans= rev(x);
22
23        if(ans>INT_MAX || ans<INT_MIN) return 0;
24        return ans;
25    }
26};