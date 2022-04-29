class Solution {
public:
    int findComplement(int num) {
        int complementNum = 0, pos = 0, temp = num;
        while(temp) {
            if(!(temp & 1))
                complementNum |= (1<<pos);
            temp = temp >> 1;
            ++pos;
        }
        return complementNum;
    }
};