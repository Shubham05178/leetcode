/**
Leetcode Problem - https://leetcode.com/problems/boats-to-save-people/
Author - Shubham Nagaria
Date - 24th March 2022
Boats to Save People
**/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        multiset<int>s(people.begin(),people.end());
        int c = 0, w1, diff;
        while(s.size()!=0){
            w1 = *s.begin();
            s.erase(s.begin());
            diff = limit - w1;
            while(diff!=0 && s.find(diff)==s.end())
                diff--;
            if(diff != 0) s.erase(s.find(diff));
            c++;
        }
        return c;
    }
};