class Solution {
public:
    bool static comp(int a, int b) {
        return a > b;
    }
    int hIndex(vector<int>& citations) {
        int Size = citations.size(), idx;
        sort(citations.begin(), citations.end(), comp);
        for( idx = 0; idx < Size; idx++) {
            if(idx >= citations[idx]){
                break;
            }
        }
        return idx;
    }
};