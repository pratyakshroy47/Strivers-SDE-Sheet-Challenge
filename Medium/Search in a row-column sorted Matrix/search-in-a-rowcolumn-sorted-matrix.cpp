//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
   bool solver(vector<vector<int> > &a , int n , int m , int x, int i)
    {
        int low = 0; int high = m-1;
        while(low<=high)
        { int mid = (low+high)/2;
           
            if(a[i][mid]==x)
            return true ;
            else if(a[i][mid]< x)
            low= mid+1;
            else
            high = mid-1;
            
        }
        return false ;
        
    }
     bool solvec(vector<vector<int> > &a , int n , int m , int x, int j)
    {
        int low = 0; int high = n-1;
        while(low<=high)
        { int mid = (low+high)/2;
           
            if(a[mid][j]==x)
            return true ;
            else if(a[mid][j ]< x)
            low= mid+1;
            else
            high = mid-1;
            
        }
        return false ;
        
    }
    bool search(vector<vector<int> > a, int n, int m, int x) 
    {
       for(int i =0;i<n;i++)   // for rows 
       {
           if(x>=a[i][0] && x<=a[i][m-1]){
           if( solver(a, n, m, x, i)==true)
           return true ;
           }
           
       }
         for(int j =0;j<m;j++)    // for column 
       {
           if(x>= a[0][j] && x<= a[n-1][j]){
           if(solvec(a, n, m, x, j)==true)
           return true ;}
           
           
       }
       return false;
       
    }
};

//{ Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 


// } Driver Code Ends