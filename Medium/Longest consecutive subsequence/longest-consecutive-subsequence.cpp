//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
       int maxi=0,cnt=0,maxel=0;
        unordered_map<int,int> m;
        for(int i=0;i<N;i++)
        {
            m[arr[i]]++;
            maxel=max(maxel,arr[i]);
        }
        for(int i=0;i<=maxel;i++)
        {
            if(m.find(i)!=m.end())
            {
                cnt++;
                maxi=max(maxi,cnt);
            }
            else cnt=0;
            
        }
        return maxi;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends