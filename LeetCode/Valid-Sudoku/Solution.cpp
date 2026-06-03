1class Solution {
2public:
3    bool isSafe(int i, int j, vector<vector<char>>& board) {
4        for (int ind = 0; ind < 9; ind++) {
5
6            // col check
7            if ((ind != i) && (board[ind][j] == board[i][j]))
8                return false;
9            // row check
10            if ((ind != j) && (board[i][ind] == board[i][j]))
11                return false;
12            int r = (3 * (i / 3)) + (ind / 3);
13            int c = (3 * (j / 3)) + (ind % 3);
14            if ((r != i || c != j) && board[r][c] == board[i][j])
15                return false;
16        }
17        return true;
18    }
19    bool isValidSudoku(vector<vector<char>>& board) {
20        for (int i = 0; i < board.size(); i++) {
21            for (int j = 0; j < board[0].size(); j++) {
22                if (board[i][j] != '.' && isSafe(i, j, board) == false)
23                    return false;
24            }
25        }
26        return true;
27    }
28};