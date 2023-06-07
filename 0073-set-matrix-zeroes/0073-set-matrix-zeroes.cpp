class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row[n]; // row array
        int col[m]; // col array
        for(int i=0;i<n;i++){
            row[i] = 0;
        }
        for(int j=0;j<m;j++){
            col[j] = 0;
        }
        // for(int i=0;i<n;i++){
        //     cout<<row[i]<<" ";
        // }cout<<"\n";
        // for(int j=0;j<m;j++){
        //     cout<<col[j]<<" ";
        // }cout<<"\n";
        // Traverse the matrix:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<row[i]<<" ";
        // }cout<<"\n";
        // for(int j=0;j<m;j++){
        //     cout<<col[j]<<" ";
        // }cout<<"\n";
        // Finally, mark all (i, j) as 0
        // if row[i] or col[j] is marked with 1.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};