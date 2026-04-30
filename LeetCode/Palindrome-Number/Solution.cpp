1class Solution {
2public:
3    bool isPalindrome(int x) {
4        if(x<0) return false;
5        else {
6            int y=x;
7            long long sum=0;
8            while(y>0){
9                int r= y % 10;
10                sum= sum*10 + r;
11                y/=10;
12            }
13            if(sum==x) return true;
14            return false;
15        }
16    }
17};