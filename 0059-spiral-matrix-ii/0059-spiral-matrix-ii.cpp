class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if( n <= 0) return {};
        vector<vector<int>> dir{ {0, 1}, {1, 0}, {0, -1}, {-1,0}};
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int i = 0, j = -1, d = 0, N = n*n, flag = 0;
        
        while(flag < N) {
            int ni = i + dir[d][0], nj = j + dir[d][1];
            while(ni < 0 || ni >= n || nj < 0 || nj >= n || matrix[ni][nj] != 0) {
                d = (d+1) % 4;
                ni = i + dir[d][0];
                nj = j + dir[d][1];
            }
            i = ni;
            j = nj;
            matrix[i][j] = ++flag;
        }
        return matrix;
    }
};