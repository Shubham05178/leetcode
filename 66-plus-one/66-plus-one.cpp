class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size() - 1;
        int carry = 1;
        while(idx >= 0 && carry == 1) {
            digits[idx] += carry;
            carry = digits[idx]/10;
            digits[idx] %= 10; 
            idx--;
            
        }
        if(carry){
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};