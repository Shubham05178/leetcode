class Solution {
public:
    string freqAlphabets(string s) {
        string result;
        int lenOfString = s.size(), id = 0, digits;
        while(id < lenOfString) {
            if((id + 2) < lenOfString && s[id + 2] == '#') {
                digits = ((s[id] - '0') * 10) + (s[id + 1] - '0') - 1;
                result += (digits + 'a');
                id += 3;
            }
            else {
                digits = (s[id] -'0') - 1;
                result += (digits + 'a');
                id += 1;
            }
        }
        return result;
    }
};