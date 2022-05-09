class Solution {
public:
    int findNthDigit(int n) {
       long long int len = 1, count = 9, temp = n, startnum;
        while(temp >= len * count) {
            temp -= (len * count);
            len++;
            count *= 10;
        }
        startnum = pow(10, len - 1);
        if(temp % len == 0){
            return (startnum + (temp/len) - 1)% 10;
        }
        return to_string(startnum + (temp / len)) [(temp % len) - 1] - '0';
    }
};