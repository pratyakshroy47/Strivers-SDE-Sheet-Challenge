//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
     vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
        int cols=c,row=r;
        int top = 0, left = 0, right = cols - 1, bottom = row - 1;

    while (top <= bottom && left <= right) {
        // traverse right
        for (int col = left; col <= right; col++) {
            ans.push_back(matrix[top][col]);
        }
        top++;

        // traverse down
        for (int row = top; row <= bottom; row++) {
            ans.push_back(matrix[row][right]);
        }
        right--;

        // traverse left
        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                ans.push_back(matrix[bottom][col]);
            }
            bottom--;
        }

        // traverse up
        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                ans.push_back(matrix[row][left]);
            }
            left++;
        }
 
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
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends