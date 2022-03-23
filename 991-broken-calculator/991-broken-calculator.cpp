/**
* Leetcode Problem - https://leetcode.com/problems/broken-calculator/
* Author - Shubham Nagaria
* Date - 23rd March 2022
Broken Calculator
**/
class Solution {
public:
    int brokenCalc(int startValue, int target) {
       int c = 0;
        while(target > startValue){
            if(target % 2 == 0)
                target /= 2;
            else
                target +=1;
            c++;
        }
        return c + startValue - target;
    }
};