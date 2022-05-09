class Solution {
public:
    int maxProduct(vector<string>& words) {
        int bithash, noOfWords = words.size(), wordsize, ans = 0;
        vector<vector<int>>bithashAndSize;
        for(string s : words) {
            bithash = 0;
            for(char ch : s) 
               bithash |= (1<< (ch -'a'));
            wordsize = s.size();
            bithashAndSize.push_back({bithash, wordsize});
        }
        for(int idx = 0; idx < noOfWords; idx++) {
            for(int idy = idx + 1; idy < noOfWords; idy++) {
                if((bithashAndSize[idx][0] & bithashAndSize[idy][0]) == 0)
                    ans = max(ans, bithashAndSize[idx][1] * bithashAndSize[idy][1]);
            }
        }
        return ans;
    }
};