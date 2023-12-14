//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    #define mod 1000000007
    long long countWays(int n, int k){
        // code here
        vector<pair<long long, long long>>dp(n+1);
        
        dp[1]={k,0};
        
        for(int i=2;i<=n;i++){
            
            auto p=dp[i-1];
            
            long long diff= (((p.first+p.second)%mod)*(k-1))%mod ;
            long long same=p.first;
        
            dp[i]={diff,same};
        }
        
        auto pp=dp[n];
        
        return (pp.first+pp.second)%mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends