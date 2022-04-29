class Solution {
public:
    string reformatNumber(string number) {
        int sCount = 0, idx = 0, blockSize = 3, countOfElements = 0, rem;
        for(char ch : number) {
            if(ch == ' ' || ch == '-')
                sCount++;
        }
        int len = number.size();
        string res;
        while(idx < len){
            rem = len-idx-sCount;
            if(rem > 4)
                blockSize = 3;
            else if (rem == 4)
                blockSize = 2;
            else
                blockSize = rem;
            if(blockSize == 0)
                break;
            if(res != "") 
                res += '-';
            countOfElements = 0;
            while(idx < len) {
                if(number[idx] != ' ' && number[idx] != '-') {
                    res += number[idx];
                    countOfElements++;
                    idx++;
                    if(countOfElements == blockSize)
                        break;
                    }
                    else {
                        sCount--;
                        idx++;
                    }
                }
            }
       return res; 
    }
};