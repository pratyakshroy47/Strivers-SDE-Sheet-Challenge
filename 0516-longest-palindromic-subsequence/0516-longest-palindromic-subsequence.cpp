class Solution {
public:

    int solve(string& a, string& b){
    vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));
    for(int i=a.length()-1; i>=0; i--){
        for(int j=b.length()-1; j>=0; j--){
            int ans = 0;
            if(a[i] == b[j])
                ans = 1 + dp[i+1][j+1];
            else
                ans = max(dp[i+1][j], dp[i][j+1]);

            dp[i][j] = ans; // Add this line to store the LCS length in dp array
        }
    }
    return dp[0][0];
}

    int longestPalindromeSubseq(string s) {
        string temp;
        temp = s;
        reverse(temp.begin(), temp.end());
        return solve(s, temp);
    }
};