class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long c = abs((long long)n);
        while(c > 0) {
            if(c % 2 == 1) { // odd power
                ans = ans * x;
                c = c - 1; // power gets reduced by 1
            }
            else {
                x = x * x;
                c = c / 2; // power gets reduced / 2
            }
        }
        if(n > 0) {
            return ans;
        }
        else {
            return 1.0 / ans;
        }
    }
};