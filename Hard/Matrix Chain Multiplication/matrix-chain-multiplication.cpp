//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int t[101][101];
    
    int fun(int arr[],int i,int j)
    {
        //base case
        if(i>=j)
        {
            return 0;
        }
        if(t[i][j] != -1)
        {
            return t[i][j];
        }
        int ans = INT_MAX;
        //implementation part
        for(int k=i;k<=j-1;k++)
        {
            int temp = fun(arr,i,k)+fun(arr,k+1,j)+arr[i-1]*arr[j]*arr[k];
            ans=min(temp,ans);
        }
        return t[i][j] = ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(t,-1,sizeof(t));
        return fun(arr,1,N-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends