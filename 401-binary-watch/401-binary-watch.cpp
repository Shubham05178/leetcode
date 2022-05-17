class Solution {
public:
    int bitcount(int n){
        int count = 0;
        while(n){
            if(n&1) count++;
            n=n>>1;
        }
        return count;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        for(int hours = 0; hours < 12; hours++) {
            for(int minutes = 0; minutes < 60; minutes++) {
                if(bitcount(hours)+ bitcount(minutes) == turnedOn){
                    if(minutes<10) ans.push_back(to_string(hours)+":0"+to_string(minutes));
                    else ans.push_back(to_string(hours)+":"+to_string(minutes));
                }
            }          
        }
        return ans;
    }
};