//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
          if(s1==s2) return 1;
        
        int n=s1.length(); 
        for(int i=1;i<n;i++){
            
            
            if( s2[i]== s1[0] && s2[i-1]==s1[n-1]){
             string s="";
             for(int j=i;j<n;j++) s+=s2[j];
             for(int j=0;j<i;j++) s+=s2[j];
             
             if(s==s1) return 1;
            }
        }

        
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends