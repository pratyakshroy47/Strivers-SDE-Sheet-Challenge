class Solution {
public:
    string countAndSay(int n) {
    if (n == 1) return "1";
    string s = countAndSay(n - 1);
    string result;
    int flag = 1;
    char curr = s[0];
    for (int i = 1; i < (int)s.size(); ++i) {  // Start from index 1
        if (s[i] == curr) {
            ++flag;
        } else {
            result += to_string(flag) + curr;  // Append flag first, then curr
            curr = s[i];
            flag = 1;
        }
    }
    result += to_string(flag) + curr;  // Append the last count and character
    return result;
}
};