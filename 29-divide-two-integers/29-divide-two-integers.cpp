class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int  n=dividend, m=divisor;
        int sign =1;
        if(m==1)
            return n;
        if(m<0) sign =-sign;
        if(n<0)sign =-sign;
        
        m=abs(m);
        n=abs(n);
        long long int q=0;
        for(int i =30; i >=0; i--){
            if ( (m <<i)<=n)
            {
                n-=(m<<i);
                q+=(1<<i);
            }
        }
        if(sign<0)q=-q;
        if(q>INT_MAX)
            return INT_MAX;
        if(q<INT_MIN)
            return INT_MIN;
        return (int)q;
    }
};