class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
      string ans = "";  
      bool isNegative = false;
      if(numerator < 0 && denominator < 0)
        isNegative = false;
      else if(numerator < 0 || denominator < 0)
        isNegative = true;
    long int numerator1 = abs(numerator);
     long int denominator1 = abs(denominator);
      long int rem = numerator1 % denominator1;
      ans += to_string(numerator1 / denominator1);
      if(rem == 0) {
        if(ans > "0")
          ans = !isNegative ? ans : "-" + ans;
        return ans;
      }
       ans = !isNegative ? ans : "-" + ans;
      ans += '.';
      unordered_map<int , int>rIndex;
      string r = "";
      int i = 0;
      while(rem != 0){
        rem = rem * 10;
        r += to_string(rem / denominator1);
        if(rIndex.find(rem) != rIndex.end()){
          r.pop_back();
          r.insert(rIndex[rem], "(");
          r +=')';
          return ans + r;
        }
        rIndex[rem] = i++;
        rem = rem % denominator;
      }
      return ans + r;
    }
};