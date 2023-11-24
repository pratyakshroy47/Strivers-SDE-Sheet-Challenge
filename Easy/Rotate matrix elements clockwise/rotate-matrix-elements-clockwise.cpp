//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int M, int N, vector<vector<int>> mat) {
        int n = mat.size(), m = mat[0].size();
        
        int rowStart = 0, rowEnd = n-1, colStart = 0, colEnd = m-1;
        
        while(rowStart<rowEnd && colStart<colEnd)
        {
            int elm = mat[rowStart][colStart];
            for(int i=rowStart;i<rowEnd;i++) {
                mat[i][colStart] = mat[i+1][colStart];
            }
            
            for(int j=colStart;j<colEnd;j++) {
                mat[rowEnd][j] = mat[rowEnd][j+1];
            }
            
            for(int i=rowEnd;i>rowStart;i--) {
                mat[i][colEnd] = mat[i-1][colEnd];
            }
            
            for(int j=colEnd;j>colStart+1;j--) {
                mat[rowStart][j] = mat[rowStart][j-1];
            }
            
            mat[rowStart][colStart+1] = elm;
            rowStart++;
            colStart++;
            rowEnd--;
            colEnd--;
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(N, M, Mat);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends