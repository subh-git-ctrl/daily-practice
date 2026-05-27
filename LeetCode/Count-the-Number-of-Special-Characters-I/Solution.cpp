1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        vector<int> upper(26,0);
5        vector<int> lower(26,0);
6        int special=0;
7        for(char &c:word){
8            if(c>='a' && c<='z') lower[(c-'a')]++;
9            else upper[(c-'A')]++;
10        }
11
12        for(int i=0;i<26;i++){
13            if(upper[i]>0 && lower[i]>0) special++;
14        }
15        return special;
16    }
17};