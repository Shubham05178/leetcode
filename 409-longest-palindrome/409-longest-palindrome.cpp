class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>freq;
        for(char &ch : s)
            freq[ch]++;
        int length = 0;
        bool midis = false;
        for(char &ch : s){
             length+= freq[ch];
            if(freq[ch]%2==1 ){
                if(midis){
                    length -=1;
                }
                else
                    midis=true;
            }
             freq[ch]=0;
        }
        return length;
    }
};