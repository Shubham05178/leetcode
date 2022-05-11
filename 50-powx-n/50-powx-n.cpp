class Solution {
public:
    double pow(double x, int n){
        if(n == 0) return 1;
        if(n == 1) return x;
        double xx = pow(x, n/2);
        if((n % 2) == 0)
            return xx*xx;
        return xx*xx*x;
    }
    double myPow(double x, int n) {
        double ans = pow(x,abs(n));
        return n < 0 ? 1/ans : ans;
    }
};