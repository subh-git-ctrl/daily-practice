1class Solution {
2public:
3    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
4        sort(asteroids.begin(),asteroids.end());
5        int n=asteroids.size();
6        for(int i=0;i<n;i++){
7            if(mass>=asteroids[i]){
8                mass+=asteroids[i];
9                if(mass>asteroids[n-1]) return true;
10            }
11            else return false;
12        }
13        return false;
14    }
15};