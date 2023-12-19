//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    void solve(int m,vector<int> &v1){
        while(m!=0){
            int remainder=m%2;
            v1.push_back(remainder);
            m=m/2;
        }
    }
    int posOfRightMostDiffBit(int m, int n)
    {
        int count=0;
        vector<int>v1;
        vector<int>v2;
        solve(m,v1);
        solve(n,v2);
        int i=0;
        int j=0;
        while(i<v1.size()||j<v2.size()){
        if(v1[i]==v2[j]){
            count++;
            i++;
            j++;
        }else{
            count++;
            return count;
        }
    }
    return -1;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends