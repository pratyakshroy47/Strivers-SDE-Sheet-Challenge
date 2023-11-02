//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
          vector<int>maxleft(n);
        vector<int>maxright(n);
        maxleft[0]=arr[0];
        for(int i=1;i<n;i++){
            maxleft[i]=max(arr[i],maxleft[i-1]);
        }
        maxright[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            maxright[i]=max(arr[i],maxright[i+1]);
        }
        long long water=0;
        for(int i=0;i<n;i++){
            water += min(maxleft[i],maxright[i]) - arr[i];
        }
        return water;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends