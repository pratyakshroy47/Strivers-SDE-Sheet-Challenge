class Solution {
public:
    unordered_set<string> seen;

    void backtrack(int r, int n, vector<string> &board, vector<bool>& col, vector<bool>& d1, vector<bool> d2, vector<vector<string>>& result) {
        if(r == n) {
            result.push_back(board);
            return;
        }

        for(int c = 0; c < n; ++c) {
            if(!col[c] && !d1[r+c] && !d2[r-c+n-1]) {
                board[r][c] = 'Q';
                col[c] = d1[r+c] = d2[r-c+n-1] = true;
                backtrack(r+1, n, board, col, d1, d2, result);
                col[c] = d1[r+c] = d2[r-c+n-1] = false;
                board[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false);
        vector<bool> d1(2*n-1, false);
        vector<bool> d2(2*n-1, false);
        backtrack(0, n, board, col, d1, d2, result);
        return result;
    }

    
};