//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int>ans;
bool dec=0;

    void call(int N,int n){
        ans.push_back(n);
        if(n>=N) {
            return ;
        }
        if(n<=0) dec=true;
        if(!dec){
           call(N,n-5); 
        }else{
            call(N,n+5);
        }
    }
    vector<int> pattern(int N){
        // code here
       
       
       ans.push_back(N);
       if(N>0)
       call(N,N-5);
       return ans;
    }


};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends