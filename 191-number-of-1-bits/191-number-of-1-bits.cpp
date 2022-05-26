class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for(int pos = 31; pos >= 0; pos--){
            count+= ((1 << pos) & n) ? 1 : 0;
        }
        return count;
    }
};