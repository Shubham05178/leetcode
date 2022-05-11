class Solution {
public:
    int countVowelStrings(int n) {
        vector<int>pattern(5,1);
        int sumi = 0;
        for(int idx = 1; idx <= n;idx++){
            sumi = 1;
            for(int idy = 1; idy < 5; idy++){
                sumi+= pattern[idy];
                pattern[idy] = sumi;
            }
        }
        return sumi;
    }
};