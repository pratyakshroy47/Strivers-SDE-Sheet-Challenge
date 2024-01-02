//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
   vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
    int n=a.size(),m=a[0].size(),i,j,k,l,area=INT_MIN,r1,r2,c1,c2;
    for(i=0;i<n;i++){
        vector<int> subMatrix(m,0);
        for(j=i;j<n;j++){
            for(k=0;k<m;k++) subMatrix[k]+=a[j][k];
            map<int,int> mp;
            int sum=0,maxLen=0,startIndex,endIndex;
            for(l=0;l<m;l++){
                sum+=subMatrix[l];
                if(sum==0){
                    maxLen=l+1;
                    startIndex=0;
                    endIndex=l;
                }
                else{
                    if((mp.find(sum)!=mp.end()) && l-mp[sum]>maxLen){
                        startIndex=mp[sum]+1;
                        endIndex=l;
                        maxLen=l-mp[sum];
                    }
                    else mp[sum]=l;
                }
            }
            if(area<=(maxLen*(j-i+1)) || area==INT_MIN){
                if(area==maxLen*(j-i+1)){
                    if(startIndex<c1) r1=i,r2=j,c1=startIndex,c2=endIndex;
                    else if(startIndex==c1 && r2-r1+1<j-i+1){
                        r1=i,r2=j,c2=endIndex;
                    }
                    else{}
                }
                else{
                    area=maxLen*(j-i+1);
                    r1=i,r2=j,c1=startIndex,c2=endIndex;
                }
            }
        }
    }
    vector<vector<int>> largest0Matrix;
    for(i=r1;i<=r2;i++){
        vector<int> row;
        for(j=c1;j<=c2;j++) row.push_back(a[i][j]);
        largest0Matrix.push_back(row);
    }
    return largest0Matrix;
  }
};


//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends