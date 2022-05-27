class Solution {
public:
    int numberOfSteps(int num) {
        int c=0,n=num;
        while(n){
            if((n&1)==1) {
                n-=1;
                c++;
            }
            if(n){
            c++;
            n=n>>1;
            }
        }
        return c;
    }
};