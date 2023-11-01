//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int n)
    {
        // your code here
        string ans = "" ;
            
        if(n==1){
            for(int i = 0 ; i<arr[0].size() ; i++){
                ans += arr[0][i];
            }
        }
                bool f =1; int i  = 0 ; int j = 0 ;
                while(j<arr[i].size() && i < n-1){
                    
                    if(arr[i][j] != arr[i+1][j]) {f=0 ;break;}
                    
                    else i++;
                    
                    if(i==n-1 && f==1) {
                        ans +=arr[i][j];
                        i = 0;
                        j++;
                    }
                }
               
            
            
            if(ans=="") return "-1";
            
            return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends