/**
* Leetcode Problem - https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/
* Author - Shubham Nagaria
* Date - 10th April 2022
Minimize Result by Adding Parentheses to Expression
**/
class Solution {
public:
    string minimizeResult(string expression) {
        int n = expression.size(),ans = INT_MAX, plus, cal;
        string res;
        for(int i =0;i < n;i++){
            if(expression[i] == '+' ){
                plus = i;
                break;
            }
        }
        for(int i = 0; i < plus;i++){
            int left = 0;
            for(int j = 0; j <i; j++)
                left = left*10+(expression[j]-'0');
            if(left == 0)
                left =1;
            for(int rt = n-1; rt>plus;rt--){
                int right = 0;
                for(int j = rt+1;j < n;j++)
                    right = (right*10) +(expression[j]-'0');
                if(right == 0 ) 
                    right = 1;
                int leftmid = 0,rightmid = 0;
                for(int j = i; j<plus; j++)
                    leftmid = (leftmid*10) + (expression[j]-'0');
                for(int j = plus+1; j <= rt;j++)
                    rightmid = (rightmid*10)+ (expression[j]-'0');
                cal = (leftmid+rightmid)*left*right;
                if(ans>cal){
                    ans = cal;
                    string s = expression;
                    s.insert(s.begin()+i,'(');
                    s.insert(s.begin()+rt+2,')');
                    res=s;
                }
            }
        }
        return res;
    }
};