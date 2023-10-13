class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;
        long long exponent = n;

        if(exponent < 0) {
            x = 1.0 / x;
            exponent = -exponent;
        }

        while(exponent > 0) {
            if(exponent % 2 == 1) {
                result *= x;
            }
            x *= x;
            exponent /= 2;
        }
        return result;
    }
};