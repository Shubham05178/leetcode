class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> charAtIndex (26, INT_MIN);
        int sizeOfString = s.size() , maximumSubstringlength = -1;
        for(int id = 0; id < sizeOfString; id++) {
            int charToIntId = s[id] - 'a';
            if(charAtIndex[charToIntId] != INT_MIN){
                maximumSubstringlength = max(maximumSubstringlength, (id - 1) - charAtIndex[charToIntId]);
            }
            else {
                charAtIndex[charToIntId] = id;
            }
        }
        return maximumSubstringlength;
    }
};