class Solution {
public:
    int findLUSlength(string a, string b) {
        int sizeOfA = a.size(), sizeOfB = b.size(), lenOfLCS, lenOfLUS;
        if(sizeOfA > sizeOfB)
            return sizeOfA;
        if( sizeOfA < sizeOfB )
            return sizeOfB;
        if(a == b )
            return -1;
        return sizeOfA;
        
    } 
};

// "aefawf awfafaw"
// "aefawf awfafwaef"
// "aefawfawfawfaw"
// "aefawfeawfwafwaef"
// aefawfawfafa