//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     bool isSafe(vector<vector<bool>> &board, int n, int r, int c) {
        for (int i = 0; i < r; i++)
            if (board[i][c]) return false;
        for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
            if (board[i][j]) return false;
        for (int i = r, j = c; i >= 0 && j < n; i--, j++)
            if (board[i][j]) return false;
        return true;
    }
    
    void find_positions(vector<vector<bool>> &board, vector<int> &queen_positions, vector<vector<int>> &ans, int n, int r) {
        if (r == n) {
            ans.push_back(queen_positions);
            return;
        }
    
        for (int c = 0; c < n; c++) {
            if (isSafe(board, n, r, c)) {
                board[r][c] = true;
                queen_positions.push_back(c + 1);
                find_positions(board, queen_positions, ans, n, r + 1);
                queen_positions.pop_back();
                board[r][c] = false;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        vector<vector<int>> ans;
        vector<int> queen_positions;
    
        find_positions(board, queen_positions, ans, n, 0);
    
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends