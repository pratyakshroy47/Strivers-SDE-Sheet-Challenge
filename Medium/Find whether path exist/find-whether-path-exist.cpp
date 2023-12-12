//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
     void dfs(int i,int j,int n,int m,vector<vector<int>>& grid,bool &flag){
        if(i<0||i>=n||j<0||j>=m||grid[i][j]==0)
         return ;
         
         if(grid[i][j]==2){
         flag=true;
         return ;
         }
         grid[i][j]=0;
         dfs(i+1,j,n,m,grid,flag);
          dfs(i-1,j,n,m,grid,flag);
           dfs(i,j+1,n,m,grid,flag);
            dfs(i,j-1,n,m,grid,flag);
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {   
        int n=grid.size();
        int m=grid[0].size();
        bool flag=false;
        
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]==1)
               dfs(i,j,n,m,grid,flag);
           }
       }
       return flag;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends