//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
       int n = S.length(), cnt = 0, lag = 0, prev = 0, loc = 0;
        string ans = "";
        vector<int> store(8, 0);
        for(int i = n-1; i>= 0; i--){
            if(S[i] == 'D'){
                cnt++;
            }
            if(S[i] == 'I'){
                lag = i;
                store[lag] = cnt;
                cnt = 0;
            }
            if(i==0 && S[i] == 'D'){
                store[0] = cnt;
            }
        }
        if(S[0]== 'I'){
            ans += ('1');
            prev = 1;
        }
        else{
            ans += ('0' + (store[0] + 1));
            prev = store[0] + 1;
        }
        for(int i = 0; i < n; i++){
            if(S[i] == 'I'){
                loc = 0;
                ans += '0' + (prev + store[i] + 1);
                prev = prev + store[i] + 1;
            }
            else{
                loc++;
                ans += '0' + (prev - loc);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends