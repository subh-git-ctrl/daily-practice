1class Solution {
2public:
3    int reverseBits(int n) {
4        int m=n;
5        
6        int noOfDigits=0;
7        while(m!=0){
8            noOfDigits++;
9            m/=10;
10        }
11
12        int m2=n;
13        long long sum=0;
14        int c=31;
15        while(m2!=0){
16            int rem= m2%2 ;
17            sum+= pow(2,c)*rem;
18            c--;
19            m2/=2;
20        }
21        return sum;
22        
23    }
24};