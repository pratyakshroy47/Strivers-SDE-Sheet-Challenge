//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string s){
           string rev=s;
    reverse(rev.begin(),rev.end());
    int size=s.size();
    s+='$';
    s+=rev;
    //lps
    int prefix=0,suffix=1;
    vector<int>lps(s.size(),0);
    while(suffix<s.size()){
        //match
        if(s[prefix]==s[suffix]){
            lps[suffix]=prefix+1;
            suffix++,prefix++;
        }
        //not match
        else{
            if(prefix==0){
                suffix++;
            }
            else{
                prefix=lps[prefix-1];

            }
        }
    }
        return size- lps[s.size()-1];
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends