//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
         int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n , vector<bool>(m , false));
        
        int time = -1;
        
        queue<pair<int , int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    // rotten
                    q.push({i , j});
                    visited[i][j] = true;
                }
            }
        }
        
        if(q.empty()){
            // no rotten oranges or empty grid
            return 0;
        }
        
        while(!q.empty()){
            int size = q.size();
            // process each level
            for(int i=0; i<size; i++){
                pair<int , int> front = q.front();
                q.pop();
                
                int row = front.first;
                int col = front.second;
                
                int delrow[] = {-1 , 0 , 1 , 0};
                int delcol[] = {0 , 1 , 0 , -1};
                
                for(int j=0; j<4; j++){
                    int nrow = row + delrow[j];
                    int ncol = col + delcol[j];
                    
                    if(nrow<n && nrow>=0 && ncol<m && ncol>=0
                        && grid[nrow][ncol] == 1 && !visited[nrow][ncol]){
                            q.push({nrow , ncol});
                            visited[nrow][ncol] =  true;
                        }
                }
            }
            
            time++;
        }
        
        // check wether all oranges are rotten or not
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    return -1;
                }
            }
        }
        return time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends