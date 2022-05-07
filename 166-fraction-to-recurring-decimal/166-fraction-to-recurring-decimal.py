class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
      isNegative = False
      if numerator < 0 and denominator < 0:
        isNegative = False
      elif numerator < 0  or denominator < 0:
        isNegative = True
      denominator = abs(denominator)
      numerator = abs(numerator)
      rem = numerator % denominator
      ans = str(numerator // denominator)
      if rem == 0:
        if ans > "0":
          ans = ans if not isNegative else "-" + ans
        return ans
      ans = ans if not isNegative else "-" + ans
      ans += "."
      afterDecimal = ""
      i = 0
      remToIndex ={}
      while rem != 0:
        rem *= 10
        afterDecimal += str(rem // denominator)
        if rem in remToIndex:
          afterDecimal = afterDecimal[0:remToIndex[rem]] + "(" + afterDecimal[remToIndex[rem]: -1]+")"
          return ans + afterDecimal
        remToIndex[rem]= i
        i+=1
        rem = rem % denominator 
      return ans + afterDecimal
