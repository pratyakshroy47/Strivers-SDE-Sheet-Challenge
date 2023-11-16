//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        vector<int> a(26, 0);
        int cnt=0, i=0, j=0, n=s.size(), l=-1, r=-1;
    
        for(char i: p){
        	a[i-'a']++;
        	if(a[i-'a']==1) cnt++;
        }
    
        while(j<n){
        	a[s[j]-'a']--;
        	if(a[s[j]-'a']==0) cnt--;
    
        	while(cnt==0){
        		if( (l==-1 && r==-1) || ((r-l)>(j-i)) ){
        			l=i;
        			r=j;
        		}
    
    	    	a[s[i]-'a']++;
    	    	if(a[s[i]-'a']==1) cnt++;
    	    	i++;
        	}
    
        	j++;
        }
    
        if(l==-1 && r==-1) return "-1";
    
        string ans="";
    
        for(int i=l; i<=r; i++) ans+=s[i];
    
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
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends