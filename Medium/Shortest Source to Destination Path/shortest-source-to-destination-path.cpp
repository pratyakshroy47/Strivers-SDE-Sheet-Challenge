//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        int n=A.size();
        int m=A[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        
        if(A[0][0]==0){
            return -1;
        }
        
        queue<pair<int,int>>q;
        q.push(make_pair(0,0));
        dist[0][0]=0;
        vis[0][0]=true;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            int dr[]={0,0,1,-1};
            int dc[]={-1,1,0,0};
            for(int k=0;k<4;k++){
                int nrow=i+dr[k];
                int ncol=j+dc[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && A[nrow][ncol]==1 && vis[nrow][ncol]==false){
                    vis[nrow][ncol]=true;
                    dist[nrow][ncol]=1+dist[i][j];
                    q.push(make_pair(nrow,ncol));
                }
            }
            
        }
        if(dist[X][Y]==INT_MAX){
            return -1;
        }
        return dist[X][Y];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends