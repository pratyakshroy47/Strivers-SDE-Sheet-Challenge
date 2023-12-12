//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> matrix)
    {
         int n=matrix.size();
       int m=matrix[0].size();
       for(int i=1;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
             matrix[i][j]=matrix[i][j]+max(matrix[i-1][j],max(j!=0?matrix[i-1][j-1]:0,j!=n-1?matrix[i-1][j+1]:0));
           }
       }
       int maxi=0;
       for(int j=0;j<m;j++)
       {
        maxi=max(maxi,matrix[n-1][j]);    
       }
       return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends