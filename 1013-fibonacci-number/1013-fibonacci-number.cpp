class Solution {
public:
    // Using Memoization (Top-Down)
    // int f(int n, vector<int> &dp){
    //     if(n<=1) return n;

    //     if(dp[n]!=-1) return dp[n];

    //     return dp[n] = f(n-1,dp) + f(n-2, dp);
    // }

    // int fib(int n) {
    //     vector<int> dp(n+1, -1);
    //     return f(n, dp);
    // }

    //Using Tabulation

    int fib(int n){
        if(n==0 || n==1) return n;

        int prev2=0;
        int prev=1;
        int curr=0;
        for(int i=2; i<=n; i++){
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }


};