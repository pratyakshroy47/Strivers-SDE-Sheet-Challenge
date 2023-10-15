class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        string ans;
        for(; i>= 0 || j >= 0; --i, --j) {
            if(i >= 0) carry += a[i] -'0';
            if(j >= 0) carry += b[j] - '0';
            ans += (carry & 1) + '0';
            carry >>= 1;
        }

        if(carry > 0) ans += carry + '0';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};