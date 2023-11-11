//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
             map<char,int>mapA;
            map<char,int>mapB;
            for(auto i:A){
                mapA[i]++;
            }
            
            for(auto i:B){
                mapB[i]++;
            }
            string ans = "";
            
            for(auto i:mapA){
                if(mapB.find(i.first) == mapB.end()){
                    ans+=i.first;
                }
            }
            
            for(auto i:mapB){
                if(mapA.find(i.first)==mapA.end()){
                    ans+=i.first;
                }
            }
            sort(ans.begin(),ans.end());
            if(ans.size() == 0){
                return "-1";
            }return ans;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends