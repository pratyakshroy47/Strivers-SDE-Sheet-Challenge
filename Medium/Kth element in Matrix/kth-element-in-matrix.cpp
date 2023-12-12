//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



void heapify(int mat[MAX][MAX],int n,int i,int N){
    
    int left_index=(2*i) +1;
    int right_index=(2*i) +2;
    int largest=i;
    
    if(left_index < n && mat[largest/N][largest%N] < mat[left_index/N][left_index%N]){
        largest=left_index;
    }
    if(right_index <n && mat[largest/N][largest%N] < mat[right_index/N][right_index%N] ){
        largest=right_index;
    }
    
    if(largest!=i){
        swap(mat[largest/N][largest%N],mat[i/N][i%N]);
        
        heapify(mat,n,largest,N);
    }
}

void build_heap(int mat[MAX][MAX],int n,int N){
    
    for(int i=(n/2)-1; i>=0; i--){
        heapify(mat,n,i,N);
    }
}

void heap_sort(int mat[MAX][MAX],int n,int N){
    
    build_heap(mat,n,N);
    
    int index=n-1;
    
    
    while(n!=0){
        swap(mat[0][0],mat[index/N][index%N]);
        index--;
        n--;
        heapify(mat,n,0,N);
    }
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // i/n== row and i%n==> column
    
    int N=n;
    
    
    heap_sort(mat,n*n,N);
    //build_heap(mat,n,N);
    
    return mat[(k-1)/N][(k-1)%N];
    
    
}
