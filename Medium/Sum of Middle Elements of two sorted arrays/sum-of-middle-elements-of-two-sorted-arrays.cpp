//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
           int i = 0, j = 0, cnt = 0;
            
            int sum = 0;
            
            while(i < n && j < n)
            {
                cnt++;
                
                if(ar1[i] <= ar2[j])
                {
                    if(cnt == n || cnt == n + 1) sum = sum + ar1[i];
                    
                    i++;
                }
                
                else 
                {
                    if(cnt == n || cnt == n + 1) sum = sum + ar2[j];
                    
                    j++;
                }
                
                if(cnt == n + 1) return sum;
            }
            
            while(i < n)
            {
                cnt++;
                
                if(cnt == n || cnt == n + 1) sum = sum + ar1[i];
                    
                i++;
                
                if(cnt == n + 1) return sum;
            }
            
            while(j < n)
            {
                cnt++;
                
                if(cnt == n || cnt == n + 1) sum = sum + ar2[j];
                    
                j++;
                
                if(cnt == n + 1) return sum;
            }
            
            return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends