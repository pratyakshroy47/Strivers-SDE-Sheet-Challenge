//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
          int n=nums.size();
        if(n%2!=0)return false;
        unordered_map<int,int>mp;//for storing remainder
        int pair=0;
        for(int i=0;i<nums.size();i++){
             int rem=nums[i]%k;
             if(rem==0){
                 mp[0]++;
                 if(mp[0]%2==0){
                  pair++;
                  mp[0]=mp[0]-2;
                 }
                 
             }
            else  if(mp.find(k-rem)!=mp.end() && mp[k-rem]>0){
                   pair++;
                   mp[k-rem]--;
                  // if(mp[k-rem]==0)mp.erase(mp[k-rem]);
             }
             
             else mp[rem]++;
             
        }
        
        if(pair*2==n)return true;
       
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends