class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty()) return {1};
        int carry = 1, n = digits.size();
        for(int i = n-1; i >= 0; --i) {
            carry += digits[i];
            digits[i] = carry % 10;
            carry /= 10;
        }
        if(carry > 0) 
            digits.insert(digits.begin(), carry);

        return digits;
    }
};