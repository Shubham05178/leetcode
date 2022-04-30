class Solution {
public:
    string digitsMap[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void makeCombinations(int i, int digitsSize, string word, string digits, vector<string> & ans) {
        if(i == digitsSize){
          ans.push_back(word);
          return;
        }
      int idx = (digits[i] - '0');
      for(auto ch : digitsMap[idx]) {
        makeCombinations(i + 1, digitsSize, word + ch, digits, ans);
      }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int digitsSize = digits.size();
        if(digitsSize > 0) makeCombinations(0, digitsSize, "", digits, ans);
        return ans;
    }
};