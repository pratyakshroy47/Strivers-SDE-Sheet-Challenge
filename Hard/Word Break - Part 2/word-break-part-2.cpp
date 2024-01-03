//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isValid(string temp, set<string> st) {
        return st.find(temp) != st.end();
    }
    
    void solve(string op, string ip, set<string> st, vector<string>& ans) {
        if (ip.size() == 0) {
            ans.push_back(op);
        }
    
        for (int i = 0; i < ip.size(); i++) {
            string temp = ip.substr(0, i + 1);
            if (isValid(temp, st)) {
                string op1 = op;
    
                for (auto j : temp) {
                    op1.push_back(j);
                }
                string ip1 = ip.substr(i + 1);
                if (ip1.size() != 0)
                    op1.push_back(' ');// range-based for loop to iterate over the characters in the temp string.
    
                solve(op1, ip1, st, ans);
            }
        }
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s) {
        set<string> st(dict.begin(), dict.end());
        vector<string> ans;
        solve("", s, st, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends