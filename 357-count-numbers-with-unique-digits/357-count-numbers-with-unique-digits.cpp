class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        long int sum = 10, pvmul = 9,currmul = 9;
        int mul = 9;
        while(currmul && --n ){
            pvmul = pvmul * currmul--;
            sum += pvmul;
        }
        return sum;
    }
};