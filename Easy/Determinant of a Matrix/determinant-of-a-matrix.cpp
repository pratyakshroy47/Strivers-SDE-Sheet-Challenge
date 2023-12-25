//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
          if(n == 1) return matrix[0][0];
        
        int ans = 0;
        for(int k = 0;k<n;k++){
            vector<vector<int>> Inner(n-1,vector<int>(n-1));
            int p = 0;
            int q = 0;
            for(int i = 1;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(j == k) continue;
                    Inner[p][q] = matrix[i][j];
                    q++;
                }
                q = 0;
                p++;
            }
            
            int del = matrix[0][k]*determinantOfMatrix(Inner,n-1);
            if(k%2 == 0){
                ans = ans + del;
            }
            else ans = ans - del;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends