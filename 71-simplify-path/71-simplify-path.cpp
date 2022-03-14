/**
* Leetcode Problem - https://leetcode.com/problems/simplify-path/
* Author - Shubham Nagaria
* Date - 14th March 2022
Simplify Path
**/
class Solution {
public:
    string simplifyPath(string path) {
        string res="";
        vector<string>result;
        for(char ch: path){
            if(ch=='/'){
                if(res==".."){
                    if(result.size()>0)
                    result.pop_back();
                }
                else if(res !="" && res!="."){
                    result.push_back(res);
                }
                res.clear();
            }
            else res.push_back(ch);
        }
        if(res==".."){ 
            if(result.size()>0)
                result.pop_back();
        }
        else if(res !="" && res!="."){
            result.push_back(res);
        }
        if(result.size()==0) return "/";
        res="";
            for(auto i : result)
              res += "/"+i;
        return res;
    }
};