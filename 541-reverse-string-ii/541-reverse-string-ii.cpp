class Solution {
public:
    string reverseStr(string s, int k) {
        string res="";
        int size = s.size(), idy;
        for(int idx = 0; idx < size;){
            if(idx + 2*k < size){
                idy = idx + k - 1;
                while(idy>=idx){
                    res+=s[idy--];
                }
                idy = idx+k;
                while(idy< idx+2*k){
                    res+= s[idy++];
                }
                idx= idx + 2*k;
            }
            else{
                if(idx+k>size){
                    idy = size-1;
                    while(idy>=idx){
                        res+= s[idy--];
                    }
                    idx= size;
                }
                else if(idx + 2*k >=size){
                    idy = idx+k-1;
                    while(idy>=idx){
                        res+= s[idy--];
                    }
                    idy = idx+k;
                    while(idy<size){
                        res+=s[idy++];
                    }
                    idx = size;
                }
            }
        }
        return res;
    }
};