class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0, late = 0;
        for(char & ch : s){
            if(ch == 'A'){
                late = 0;
                absent++;
            }
            if(ch == 'L')
                late++;
            if(late > 2)
                return false;
            if(ch =='P')
                late = 0;
        }
        return late < 3 and absent < 2;
    }
};