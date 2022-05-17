class Solution {
public:
    string addStrings(string num1, string num2) {
        int idx = num1.size()-1, idy = num2.size()-1, carry = 0, sum;
        string res="";
        while(idx>=0 || idy >=0 || carry > 0){
            sum = 0;
            if(idx>=0)
                sum+= num1[idx--]-'0';
            if(idy>=0)
                sum+=num2[idy--]-'0';
            sum+= carry;
            res= to_string(sum%10) + res;
            carry= sum/10;
        }
        return res;
    }
};