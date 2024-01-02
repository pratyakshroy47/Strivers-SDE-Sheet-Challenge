//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class node{
    public:
    int data;
    int row;
    int col;
    node(int data,int i,int j){
        this->data=data;
        row=i;
        col=j;
    }
};
class compare{
  public:
  bool operator()(node* a,node*b){
      return a->data > b->data;
  }
};
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          pair<int,int> ans;
          priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
          
          int maxi = -1;
          for (int i=0; i<k; i++) {
              pq.push({arr[i][0],{i,0}});
              maxi = max(arr[i][0],maxi);
          }
          
          int diff = INT_MAX;
          while(true) {
              pair<int,pair<int,int>> mini = pq.top();
              pq.pop();
              if (diff > maxi-mini.first) {
                  ans.first = mini.first;
                  ans.second = maxi;
                  diff = ans.second-ans.first;
              }
              mini.second.second++;
              if (mini.second.second >= n) break;
              mini.first = arr[mini.second.first][mini.second.second];
              if (mini.first>maxi) maxi = mini.first;
              pq.push(mini);
          }
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
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends