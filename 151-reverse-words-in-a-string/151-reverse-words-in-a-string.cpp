/**
* Leetcode Problem - https://leetcode.com/problems/reverse-words-in-a-string/
* Author - Shubham Nagaria
* Date - 23rd April 2022
Reverse Words in a String
**/
class Solution {
public:
    string reverseWords(string s) {
        string finalstring , word;
        for(char& ch : s){
            if(ch == ' '){
                if(finalstring.size() > 0 && word != "")
                    finalstring = ' ' + finalstring;
                if(word != " ")
                    finalstring.insert(finalstring.begin(),word.begin(),word.end());
                word.clear();
            }
            else{
                word += ch;
            }
        }
        if(finalstring.size() > 0 && word!= "") 
            finalstring = ' ' + finalstring;
        if(word != "")
            finalstring.insert(finalstring.begin(),word.begin(),word.end());
        return finalstring;
    }
};