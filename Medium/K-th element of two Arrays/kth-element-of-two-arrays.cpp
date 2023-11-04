//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    int i1 = 0, i2 = 0;
    while (i1 < n && i2 < m) {
        if (--k == 0) {
            return min(arr1[i1], arr2[i2]);
        }
        if (arr1[i1] < arr2[i2]) {
            ++i1;
        } else {
            ++i2;
        }
    }
    while (i1 < n) {
        if (--k == 0) {
            return arr1[i1];
        }
        ++i1;
    }
    while (i2 < m) {
        if (--k == 0) {
            return arr2[i2];
        }
        ++i2;
    }
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends