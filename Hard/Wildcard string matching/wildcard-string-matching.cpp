//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
   int solve(int i, int n, int j, int m, string& wild, string& pattern){
        // base case    
        if(i == n && j == m) return 1;
        if(i == n || j == m) return 0;
        // if dono same hai then
        if(wild[i] == pattern[j]) return solve(i+1, n, j+1, m, wild, pattern);
        // agar wild ? hai to
        if(wild[i] == '?') return solve(i+1, n, j+1, m, wild, pattern);
        // agar wild * hai to
        if(wild[i] == '*') return solve(i, n, j+1, m, wild, pattern) | solve(i+1, n, j+1, m, wild, pattern);
        return 0;
    }
    bool match(string wild, string pattern)
    {
        int n = wild.size();
        int m = pattern.size();
        return solve(0, n, 0, m, wild, pattern);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends