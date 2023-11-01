//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
         unordered_map<int, int> preSumMap;
        int sum = 0;
        int maxLen = 0;
        int k=0;
        for (int i = 0; i < n; i++) 
        {
            //calculate the prefix sum till index i:
            sum += a[i];
    
            // if the sum = k, update the maxLen:
            if (sum == k) {
                maxLen = max(maxLen, i + 1);
            }
    
            // calculate the sum of remaining part i.e. x-k:
            int rem = sum - k;
    
            //Calculate the length and update maxLen:
            if (preSumMap.find(rem) != preSumMap.end()) {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }
    
            //Finally, update the map checking the conditions:
            if (preSumMap.find(sum) == preSumMap.end()) {
                preSumMap[sum] = i;
            }
        }
       return maxLen;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends