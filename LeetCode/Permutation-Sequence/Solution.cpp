1class Solution {
2public:
3    int fact(int n){
4        if(n==0) return 1;
5        else return n*fact(n-1);
6    }
7    string Perms(int n,int k,string &s,string &set){
8        if(n==0) return s;
9
10        int f=fact(n);//24
11        int segment= f/n;//6
12        int value= k/segment ;//2--> 2nd index i.e 3 [1,2,3,4]
13        char ch=set[value];//'3'
14        s+=ch;
15        set.erase(value,1);
16        return Perms(n-1,k%segment,s,set);
17    }
18    string getPermutation(int n, int k) {
19        string set="";
20        for(int i=1;i<=n;i++){
21            set+=(i+'0');
22        }
23        string s="";
24    return Perms(n,k-1,s,set);
25
26    }
27};