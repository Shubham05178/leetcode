class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int>sfreq(26),tfreq(26);
        for(char &ch : s)
            sfreq[ch-'a']++;
        for(char &ch : target)
            tfreq[ch-'a']++;
        int maxi = INT_MAX;
        for(int idx = 0 ; idx < 26; idx++){
            if(tfreq[idx]>0)
            maxi= min(maxi,sfreq[idx]/tfreq[idx]); 
        }
        return maxi;
    }
};