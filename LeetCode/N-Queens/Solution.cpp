1class Solution {
2public:
3    bool isSafe(int row,int col,int n,vector<string> &puzzle){
4        for(int r=0;r<row;r++){
5            if(puzzle[r][col]=='Q') return false;
6        }
7
8        //left diagonals
9        for(int r=row-1,c=col-1;r>=0 && c>=0;r--,c--){
10            if(puzzle[r][c]=='Q') return false;
11        }
12        //right diagonals
13        for(int r=row-1,c=col+1;r>=0 && c<n;r--,c++){
14            if(puzzle[r][c]=='Q') return false;
15        }
16        return true;
17    }
18    void Nqueens(int r,int n,vector<string> &puzzle,vector<vector<string>> &result){
19        if(r==n){
20            result.push_back(puzzle);
21            return;
22        }
23        for(int c=0;c<n;c++){
24            if(isSafe(r,c,n,puzzle)){
25                puzzle[r][c]='Q';
26                Nqueens(r+1,n,puzzle,result);
27                puzzle[r][c]='.';
28            }
29        }
30    }
31    vector<vector<string>> solveNQueens(int n) {
32        vector<string> puzzle(n, string (n,'.'));
33        vector<vector<string>> result;
34        Nqueens(0,n,puzzle,result);
35        return result;
36    }
37};